#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 101;
int memo[N][N];

int grundy(int a, int b){
  if (memo[a][b] != -1) return memo[a][b];
  bool mex[1001];
  memset(mex, 0, sizeof mex);

  for (int i = 1; i <= a; i++) mex[grundy(a-i, b)] = 1;
  for (int i = 1; i <= b; i++) mex[grundy(a, b-i)] = 1;
  for (int i = 1; i <= min(a,b); i++) mex[grundy(a-i, b-i)] = 1;

  for (int i = 0; i <= 1000; i++)
    if (mex[i] == 0)
      return memo[a][b] = i;
  return -1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(memo, -1, sizeof memo);

  for (int i = 0; i < N; i++){
    memo[i][i] = memo[i][0] = memo[0][i] = 1000;
  }
  int n; cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++){
    int a, b; cin >> a >> b;
    if (a == b) {
      cout << "Y" << endl;
      return 0;
    }
    ans ^= grundy(a, b);
  }

  cout << (ans == 0 ? "N" : "Y") << endl;
  return 0;
}
