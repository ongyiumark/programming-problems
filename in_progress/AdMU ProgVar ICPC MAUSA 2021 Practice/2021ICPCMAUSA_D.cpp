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

const int N = 64;
ll grid[N][N];

ll mypow(ll b, ll e) {
  ll ans = 1;
  while(e > 0) {
    if (e&1) ans *= b;
    b *= b;
    e >>= 1;
  }
  return ans;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int r, c; cin >> r >> c;
  vector<int> cnt(3,0);
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> grid[i][j];
      cnt[grid[i][j]]++;
    }
  }

  if (cnt[0] >= 2) {
    cout << 0 << endl;
    return 0;
  }

  if (cnt[0] == 1) {
    if (min(r,c) > 1) {
      if (cnt[1] > 0) cout << 1 << endl;
      else cout << 2 << endl;
    }
    else {
      if (r == 1) {
        if (grid[0][0] == 0) cout << grid[0][c-1] << endl;
        else if (grid[0][c-1] == 0) cout << grid[0][0] << endl;
        else cout << min(grid[0][0], grid[0][c-1]) << endl;
      }
      else {
        if (grid[0][0] == 0) cout << grid[r-1][0] << endl;
        else if (grid[r-1][0] == 0) cout << grid[0][0] << endl;
        else cout << min(grid[0][0], grid[r-1][0]) << endl;
      }
    }
    return 0;
  }

  if (cnt[2]%2 == 0) cout << 0 << endl;
  else cout << mypow(2,cnt[2]/2) << endl;
  return 0;
}
