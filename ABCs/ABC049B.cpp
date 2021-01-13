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
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      cin >> grid[i][j];
    }
  }

  for (int i = 0; i < 2*h; i++){
    for (int j = 0; j < w; j++){
      cout << grid[i/2][j];
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
