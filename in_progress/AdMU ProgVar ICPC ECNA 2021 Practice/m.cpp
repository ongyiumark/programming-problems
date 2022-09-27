#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 55;
const int INF = 1e9;
int m, n, k;
char grid[N][N];
string words[N];

bool vis[N][N];

int di[] = {0,0,1};
int dj[] = {-1,1,0};
int memo[N][N][N][N]; // ith row, jth col, pth word, qth idx	

int dfs(int i, int j, int p, int q) {
  int &ans = memo[i][j][p][q];
  if (ans != -1) return memo[i][j][p][q];
  ans = INF;

  int sz = words[p].size();
  if (grid[i][j] != words[p][q]) return ans = INF;
  if (i == m-1 && q == sz-1) return ans = 1;

  for (int d = 0; d < 3; d++) {
    int x = i + di[d];
    int y = j + dj[d];
    if (x < 0 || x >= m || y < 0 || y >= n) continue;
    if (vis[x][y]) continue;
    if (q < sz-1) {
      vis[x][y] = 1;
      ans = min(ans, dfs(x,y,p,q+1));
      vis[x][y] = 0;
    }
    else {
      for (int pp = 0; pp < k; pp++) {
        vis[x][y] = 1;
        ans = min(ans, dfs(x,y,pp,0));
        vis[x][y] = 0;
      }
    }
  }

  ans++;
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
  for(int i = 0; i < k; i++) cin >> words[i];
  memset(memo, -1, sizeof memo);
  int ans = INF;

  for (int j = 0; j < n; j++) {
    for (int p = 0; p < k; p++) {
      vis[0][j] = 1;
      ans = min(ans,dfs(0, j, p, 0));
      vis[0][j] = 0;
    }
  }
  
  if (ans >= INF) cout << "impossible" << endl;
  else cout << ans << endl;
  
  return 0;
}
