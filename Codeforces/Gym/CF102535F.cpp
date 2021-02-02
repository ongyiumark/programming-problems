/*
  Go through each column starting from the bottom.
  Count the number of targets and stop when you encounter an obstacle.
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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--){
    int r, c;
    cin >> r >> c;
    char grid[r-1][c];
    for (int i = 0; i < r-1; i++){
      for (int j = 0; j < c; j++){
        cin >> grid[i][j];
      }
    }
    int ans = 0;
    for (int j = 0; j < c; j++){
      for (int i = r-2; i >= 0; i--){
        if (grid[i][j] == '#') break;
        ans += grid[i][j] == 'X';
      }
    }
    cout << ans << endl;
  }
  return 0;
}
