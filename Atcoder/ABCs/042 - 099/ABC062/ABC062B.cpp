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
  char grid[h+2][w+2];
  for (int i = 1; i <= h; i++){
    for (int j = 1; j <= w; j++){
      cin >> grid[i][j];
    }
  }

  for (int i = 0; i < h+2; i++){
    for (int j = 0; j < w+2; j++){
      if (i == 0 || j == 0 || i == h+1 || j == w+1) cout << "#";
      else cout << grid[i][j];
    }
    cout << endl;
  }
  return 0;
}
