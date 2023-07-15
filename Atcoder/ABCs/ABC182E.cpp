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

struct point {
  int x, y;
};

int di[] = {0,0,1,-1};
int dj[] = {-1,1,0,0};

void solve(int i, int j, int dir, vector<vector<char>>& grid, vector<vector<bool>> &vis) {
  if (grid[i][j] == '#') return;
  vis[i][j] = true;

  int h = grid.size();
  int w = grid[0].size();

  if (dir == -1) {
    for (int k = 0; k < 4; k++) {
      int x = i + di[k];
      int y = j + dj[k];
      if (x < 0 || x >= h || y < 0 || y >= w) continue;
      solve(x, y, k, grid, vis);
    }

  }
  else {
    int x = i + di[dir];
    int y = j + dj[dir];
    if (x < 0 || x >= h || y < 0 || y >= w) {}
    else solve(x, y, dir, grid, vis); 
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int h, w, n, m; cin >> h >> w >> n >> m;
  vector<vector<char>> grid(h, vector<char>(w, '.'));
  vector<pair<ll,ll>> bulbs(n);
  for (int i = 0; i < n; i++) {
    int a, b; cin >> a >> b;
    a--; b--;
    bulbs[i] = {a,b};
    grid[a][b] = 'B';
  } 

  for (int i = 0; i < m; i++) {
    int c, d; cin >> c >> d;
    c--; d--;
    grid[c][d] = '#';
  }

  vector<vector<bool>> vis_row(h, vector<bool>(w));
  for (int i = 0; i < n; i++) {
    auto &[ci, cj] = bulbs[i];
    if (vis_row[ci][cj]) continue;
    solve(ci, cj, 0, grid, vis_row);
    solve(ci, cj, 1, grid, vis_row);
  }

  vector<vector<bool>> vis_col(h, vector<bool>(w));
  for (int i = 0; i < n; i++) {
    auto &[ci, cj] = bulbs[i];
    if (vis_col[ci][cj]) continue;
    solve(ci, cj, 2, grid, vis_col);
    solve(ci, cj, 3, grid, vis_col);
  }

  int cnt = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cnt += vis_row[i][j] | vis_col[i][j];
    }
  }

  cout << cnt << "\n";
  
  return 0;
}
