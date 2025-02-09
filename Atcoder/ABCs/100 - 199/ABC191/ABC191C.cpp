/* 
  Carefully check the number of edges from the top, below, left, and right.
  
  A more elegant solution would be to notice that the number of edges is the number of vertices in a polygon.
  Consider a 2x2 window of cells. If the are 3 blacks and 1 white or 3 whites and 1 black, then it's a vertex.
*/
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

bool grid[10][10];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int h, w; cin >> h >> w;
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      char c; cin >> c;
      grid[i][j] = (c=='#');
    }
  }

  int ans = 0;
  for (int i = 0; i < h-1; i++){
    for (int j = 0; j < w-1; j++){
      bool curr = grid[i][j];
      curr ^= grid[i][j+1];
      curr ^= grid[i+1][j];
      curr ^= grid[i+1][j+1];
      ans += curr;
    }
  }
  cout << ans << endl;
  return 0;
}
