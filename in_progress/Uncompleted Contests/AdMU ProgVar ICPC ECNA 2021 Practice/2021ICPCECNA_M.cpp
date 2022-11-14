#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 55;
const int INF = 1e9;
int m, n, k;
char grid[N][N];
string words[N];

int di[] = {0, 1, 0};
int dj[] = {-1, 0, 1};
int memo[N][N][N][N][4];

int solve(int i, int j, int p, int q, int prev) {
  int &ans = memo[i][j][p][q][prev];
  int sz = words[p].size();

  if (ans != -1) return ans;
  if (grid[i][j] != words[p][q]) return ans = INF;
  if (i == m-1 && q == sz-1) return ans = 1;
  
  ans = INF;
  for (int d = 0; d < 3; d++) {
    if (prev == 2 && d == 0) continue;
    if (prev == 0 && d == 2) continue; 
    int x = i + di[d];
    int y = j + dj[d];

    if (x < 0 || x >= m || y < 0 || y >= n) continue;
    
    if (q+1 < sz) {
      ans = min(ans, 1+solve(x, y, p, q+1, d));
    }
    else {
      for (int pp = 0; pp < k; pp++) {
        ans = min(ans, 1+solve(x, y, pp, 0, d));
      }
    }
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> m >> n >> k;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }

  for (int i = 0; i < k; i++) cin >> words[i];
  memset(memo, -1, sizeof memo);

  int ans = INF;
  for (int j = 0; j < n; j++) {
    for (int p = 0; p < k; p++) {
      ans = min(ans, solve(0, j, p, 0, 3));
    }
  }

  if (ans >= INF) cout << "impossible" << endl;
  else cout << ans << endl;

  return 0;
}
