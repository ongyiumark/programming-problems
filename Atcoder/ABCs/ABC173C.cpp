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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int h, w, k; cin >> h >> w >> k;

  vector<string> grid(h);
  for (int i = 0; i < h; i++) cin >> grid[i];
  
  int total = 0;
  vector<int> row(h), col(w);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (grid[i][j] == '#') {
        total++;
        row[i]++;
        col[j]++;
      }
    }
  }
  

  int ans = 0;
  for (int maski = 0; maski < (1<<h); maski++) {
    for (int maskj = 0; maskj < (1<<w); maskj++) {
      int curr = total;
      for (int i = 0; i < h; i++) {
        if (maski&(1<<i)) {
          // row i is picked
          curr -= row[i];
        }
      }

      for (int j = 0; j < w; j++) {
        if (maskj&(1<<j)) {
          // col j is picked
          curr -= col[j];
          for (int i = 0; i < h; i++) {
            if (grid[i][j] == '#' && (maski&(1<<i))) {
              curr++;
            }
          }
        }
      }
      if (curr == k) ans++;
    }
  }

  cout << ans << "\n";

  return 0;
}
