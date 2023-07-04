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

bool solve(int i, int j, int dir, vector<vector<char>>& grid) {
  if (grid[i][j] == '#') return false;
  if (grid[i][j] == 'B') return true;

  int h = grid.size();
  int w = grid[0].size();

  bool res = false;
  if (dir == -1) {
    for (int k = 0; k < 4; k++) {
      int x = i + di[k];
      int y = j + dj[k];
      if (x < 0 || x >= h || y < 0 || y >= w) continue;
      res |= solve(x, y, k, grid);
    }

  }
  else {
    int x = i + di[dir];
    int y = j + dj[dir];
    if (x < 0 || x >= h || y < 0 || y >= w) {}
    else{
      res |= solve(x, y, dir, grid); 
    }
  }

  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int h, w, n, m; cin >> h >> w >> n >> m;
  vector<vector<char>> grid(h, vector<char>(w, '.'));
  for (int i = 0; i < n; i++) {
    int a, b; cin >> a >> b;
    a--; b--;
    grid[a][b] = 'B';
  } 

  for (int i = 0; i < m; i++) {
    int c, d; cin >> c >> d;
    c--; d--;
    grid[c][d] = '#';
  }

  int cnt = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cnt += solve(i, j, -1, grid);
    }
  }

  cout << cnt << "\n";
  
  return 0;
}
