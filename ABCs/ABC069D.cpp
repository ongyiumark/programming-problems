/*
  Zigzag pattern.
*/
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
  int n; cin >> n;
  int grid[h][w];
  int r, c;
  r = c = 0;
  for (int i = 0; i < n; i++){
    int col; cin >> col;
    while(col--){
      grid[r][c] = i+1;
      c += (r&1 ? -1 : 1);
      if (c < 0 || c >= w) {
        r++;
        c = (r&1 ? w-1 : 0);
      }
    }
  }

  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      cout << grid[i][j]; 
      cout << (j == w-1 ? "\n" : " ");
    }
  }
  return 0;
}
