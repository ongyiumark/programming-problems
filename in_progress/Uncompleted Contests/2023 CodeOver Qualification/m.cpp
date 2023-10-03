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

const int INF = 1e9;
int di[] = {0, 0, -1, 1};
int dj[] = {-1, 1, 0, 0};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, m; cin >> n >> m;
  queue<pair<int,int>> q;
  vector<vector<char>> grid(n+2, vector<char>(m+2, '-'));
  vector<vector<int>> d(n+2, vector<int>(m+2, INF));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == '-') {
        q.push({i,j});
        d[i][j] = 0;
      }
    }
  }
  for (int i = 0; i < n+2; i++) {
    q.push({i, 0}); d[i][0] = 0;
    q.push({i, m+1}); d[i][m+1] = 0;
  }
  for (int i = 0; i < m+2; i++) {
    q.push({0, i}); d[0][i] = 0;
    q.push({n+1, i}); d[n+1][i] = 0;
  }

  int ans = 0;
  while(!q.empty()) {
    auto [ci, cj] = q.front();
    q.pop();

    for (int k = 0; k < 4; k++) {
      int x = ci + di[k];
      int y = cj + dj[k];
      if (x < 0 || x >= n+2 || y < 0 || y >= m+2) continue;
      if (d[x][y] < INF) continue;

      q.push({x,y});
      d[x][y] = d[ci][cj]+1;
      ans = max(d[x][y], ans);
    }

  } 

  cout << ans << "\n";
  return 0;
}
