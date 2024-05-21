/*
  Try all 2^10 possibilities of opening shops with bitmasks.
  You can check how many shops are both open with bitwise AND and popcount.
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
  
  int n; cin >> n;
  ll shops[n];
  memset(shops, 0, sizeof shops);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < 10; j++){
      int f; cin >> f;
      if (f) shops[i] |= (1LL<<j);
    }
  }
  ll profits[n][11];
  for (int i = 0; i < n; i++){
    for(int j = 0; j <= 10; j++){
      cin >> profits[i][j];
    }
  }

  ll ans = -1e9;
  for (int i = 1; i < (1LL<<10); i++){
    ll cans = 0;
    for (int j = 0; j < n; j++){
      int cnt = __builtin_popcountll(i&shops[j]);
      cans += profits[j][cnt];
    }
    ans = max(ans, cans);
  }
  cout << ans << endl;
  return 0;
}
