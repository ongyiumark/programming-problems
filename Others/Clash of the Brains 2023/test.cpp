#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int di[] = {0,0,-1,1};
int dj[] = {-1,1,0,0};


int main() {
  cin.tie(0)->sync_with_stdio(0);

  int w = 3, h = 4;
  int ans = 0;
  for (int mask = 0; mask < (1<<h*w); mask++) {
    if (__builtin_popcount(mask) != 4) continue;
    vector grid(h, vector(w, 'X'));
    for (int idx = 0; idx < h*w; idx++) {
      if ((mask>>idx)&1) grid[idx/w][idx%w] = 'O';
    }

    vector vis(h, vector(w, false));
    function<void(int,int)> dfs = [&](int i, int j) {
      vis[i][j] = 1;
      char ch = grid[i][j];
      grid[i][j] = '.';
      for (int k = 0; k < 4; k++) {
        int x = i+di[k], y = j+dj[k];
        if (x < 0 || x >= h || y < 0 || y >= h) continue;
        if (ch != grid[x][y]) continue;
        dfs(x, y);
      }
    };

    
    int component = 0;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (vis[i][j]) continue;
        dfs(i, j);
        component++;
        
      }
    }
    if (component == 2) {
      grid.assign(h, vector(w, 'X'));
      for (int idx = 0; idx < h*w; idx++) {
        if ((mask>>idx)&1) grid[idx/w][idx%w] = 'O';
      }
      for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
          cout << grid[i][j];
        }
        cout << endl;
      }
      cout << endl;
    }
    ans += (component == 2);
  }
  cout << ans << endl;
  return 0;
}