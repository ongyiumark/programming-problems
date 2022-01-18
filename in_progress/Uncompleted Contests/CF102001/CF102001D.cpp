/*
  Fill everything except for the boundaries. 
  Then, we need at least one edge to go back to the center if we start at the corner.

  Edge cases when 2 x n or 1 x n.
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
  
  int r, c; cin >> r >> c;
  char grid[r][c];
  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){
      cin >> grid[i][j];
    }
  }

  int ans = 0;

  if (r == 1){
    for (int i = 1; i < c-1; i++) ans += grid[0][i]=='.';
    cout << ans << endl;
    return 0;
  }

  if (c == 1){
    for (int i = 1; i < r-1; i++) ans += grid[i][0]=='.';
    cout << ans << endl;
    return 0;
  }

  if (r == 2){
    for (int i = 1; i < c-1; i++) ans += (grid[0][i]=='.' && grid[1][i]=='.');
    cout << ans << endl;
    return 0;
  }

  if (c == 2){
    for (int i = 1; i < r-1; i++) ans += (grid[i][0]=='.' && grid[i][1]=='.');
    cout << ans << endl;
    return 0;
  }

  for (int i = 1; i < r-1; i++){
    for (int j = 1; j < c-1; j++){
      ans += grid[i][j]=='.';
    }
  }

  bool found = false;
  for (int i = 1; i < c-1; i++){
    if (grid[0][i] == '#' || grid[r-1][i] == '#') found = true;
  }

  for (int i = 1; i < r-1; i++){
    if (grid[i][0] == '#' || grid[i][c-1] == '#') found = true;
  }

  cout << ans + !found << endl;
  return 0;
}
