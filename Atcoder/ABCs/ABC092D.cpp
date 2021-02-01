/*
  Let's use a 100 by 100 grid.
  Fill the left half with black and the right half with white.
  We now have 1 connected component for each.

  To create another white connected component, we turn individual cells in the black side to white.
  By skipping intervals of 2, we create one additional connected component.
  We do a similar procedure for black connected components.

  This fits in the constraints because every 2 columns of black, we can create 50 connected components of white.
  We have 50 columns of black. So, that's 2500 connected components. 
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

char grid[100][100];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int a, b; cin >> a >> b;
  for (int i = 0; i < 100; i++){
    for (int j = 0; j < 100; j++){
      grid[i][j] = (j < 50 ? '#' : '.');
    }
  }

  a--; b--;
  int r, c;
  r = c = 0;
  while(a--){
    grid[r][c] = '.';
    r += 2;
    if (r >= 100){
      c += 2;
      r = 0;
    }
  }

  r = 0;
  c = 99;
  while(b--){
    grid[r][c] = '#';
    r += 2;
    if (r >= 100){
      c -= 2;
      r = 0;
    }
  }

  cout << 100 << " " << 100 << endl;
  for (int i = 0; i < 100; i++){
    for (int j = 0; j < 100; j++){
      cout << grid[i][j];
    }
    cout << endl;
  }
  return 0;
}
