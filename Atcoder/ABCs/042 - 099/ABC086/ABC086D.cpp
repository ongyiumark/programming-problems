/*
  Notice that (x,y) and (x+k, y) are always different colors.
  Thus, saying that (x,y) is white is the same as saying (x+k, y) is black.
  Thus we can change the desires to be all the same color.

  Notice also that (x,y) must be the same color with (x+2k, y) and (x, y+2k).
  Thus (x,y) must be the same color with (x%2k, y%2k).
  We can change all the desires to span [0,2k).
  
  We now have a 2k by 2k grid.
  By fixing the color of the top left cell of a k by k block, we can determine the color of all the cells.
  The problem is that the k by k blocks can loop around. We can fix this by making 4 copies of the grid.

  Now imagine we have a 2k by 2k window where the top left and bottom right are black.
  1 0
  0 1   The 1s represent black.

  We move this window over a 4k by 4k grid and count the number of desired cells are covered by the black part.
  This can be done using a 2D prefix sum.
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

const int N = 1e5;
const int K = 1001;
ll x[N], y[N];
ll pref[4*K][4*K];

int range_sum(int a, int b, int c, int d){
  int ans = pref[c][d];
  if (a > 0) ans -= pref[a-1][d];
  if (b > 0) ans -= pref[c][b-1];
  if (a > 0 && b > 0) ans += pref[a-1][b-1];
  return ans;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  memset(pref, 0, sizeof pref);
  int n, k; cin >> n >> k;
  for (int i = 0; i < n; i++){
    cin >> x[i] >> y[i];
    char c; cin >> c;
    if (c == 'W') x[i] += k;
    
    x[i]%=2*k;
    y[i]%=2*k;

    for (int a = 0; a <= 1; a++){
      for (int b = 0; b <= 1; b++){
        pref[x[i]+a*2*k][y[i]+b*2*k]++;
      }
    }
  }

  for (int i = 0; i <= 4*k; i++){
    for(int j = 0; j <= 4*k; j++){
      if (i == 0 && j == 0) continue;
      if (i == 0) pref[i][j] += pref[i][j-1];
      else if (j == 0) pref[i][j] += pref[i-1][j];
      else pref[i][j] += pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1];
    }
  }

  int ans = 0;
  for (int i = 0; i < 2*k; i++){
    for (int j = 0; j < 2*k; j++){
      int cans = range_sum(i,j,i+k-1,j+k-1) + range_sum(i+k, j+k,i+2*k-1, j+2*k-1);
      ans = max(ans, cans);
    }
  }
  cout << ans << endl;
  return 0;
}
