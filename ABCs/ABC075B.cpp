#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int h, w; cin >> h >> w;
  char grid[h][w];
  int ans[h][w];
  memset(ans, 0, sizeof ans);
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      cin >> grid[i][j];
      if (grid[i][j] == '.') continue;
      for (int di = -1; di <= 1; di++){
        for (int dj = -1; dj <= 1; dj++){
          int x = i+di;
          int y = j+dj;
          if (x < 0 || x >= h || y < 0 || y >= w) continue;
          ans[x][y]++;
        }
      }
    }
  }

  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      if (grid[i][j] == '#') cout << grid[i][j];
      else cout << ans[i][j]; 
    }
    cout << endl;
  }
  return 0;
}
