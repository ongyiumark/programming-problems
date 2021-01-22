/*
  Notice that to get to some state of the balls, the number of operations is the number of inversions.
  So, simply try all final states that satisfy the constraints.

  I initially had a backtracking solution, but that was too slow.
  The answer is DP[i][j] which counts the minimum answer for the first i white balls and the first j black balls.
  Let the cost of adding the i-th white ball given j black balls be W[i][j].
  Similarly define B[j][i] for the i-th black ball.

  Thus, DP[i][j] = min(DP[i-1][j] + W[i][j], DP[i][j-1] + B[i][j]).
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2001;
int dp[N][N], B[N][N], W[N][N];
map<pair<char, int>, int> convert;

int solve(int x, int y){
  int &ret = dp[x][y];
  if (ret != -1) return ret;
  if (x == 0 && y == 0) return ret = 0;
  ret = 1e9;
  if (y > 0) ret = min(ret, solve(x, y-1) + B[x][y]);
  if (x > 0) ret = min(ret, solve(x-1, y) + W[x][y]);
  return ret;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 0; i < 2*n; i++){
    char c; int a;
    cin >> c >> a;
    convert[{c,a}] = i;
  }

  ordered_set<int> Bset, Wset;
  for (int i = 1; i <= n; i++){
    int currB = convert[{'B',i}];
    B[0][i] = Bset.order_of_key(currB);
    Bset.insert(currB);

    int currW = convert[{'W',i}];
    W[i][0] = Wset.order_of_key(currW);
    Wset.insert(currW);
  }

  for (int i = 1; i <= n; i++){
    int w = convert[{'W',i}];
    int b = convert[{'B',i}];
    for (int j = 1; j <= n; j++){
      int currB = convert[{'B',j}];
      B[i][j] = B[i-1][j] + (w > currB);

      int currW = convert[{'W',j}];
      W[j][i] = W[j][i-1] + (b > currW);
    }
  }

  memset(dp, -1, sizeof dp);
  cout << solve(n, n) << endl;
  return 0;
}
