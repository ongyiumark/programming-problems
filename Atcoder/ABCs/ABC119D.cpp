/*
  Use binary search to find the two closest shrines and two closest temples.
  Then, try all 4 combinations.
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

const int N = 1e5+5;
ll s[N], t[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a, b, q; cin >> a >> b >> q;
  for (int i = 0; i < a; i++) cin >> s[i];
  for (int i = 0; i < b; i++) cin >> t[i];

  while(q--){
    ll x; cin >> x;
    // Get the two closest shrines 
    int lo = 0;
    int hi = a-1;
    int sans = -1;
    while(lo <= hi){
      int mid = hi-(hi-lo)/2;
      if (s[mid] <= x){
        sans = mid;
        lo = mid+1;
      }
      else hi = mid-1;
    }
    sans++;

    // Get the two closest temples
    int tans = -1;
    lo = 0;
    hi = b-1;
    while(lo <= hi){
      int mid = hi-(hi-lo)/2;
      if (t[mid] <= x){
        tans = mid;
        lo = mid+1;
      }
      else hi = mid-1;
    }
    tans++;

    ll ans = 1e18;
    // Left shrine and left temple
    if (sans > 0 && tans > 0) ans = min(ans, max(x-s[sans-1], x-t[tans-1]));

    // Right shrine and right temple
    if (sans < a && tans < b) ans = min(ans, max(s[sans]-x, t[tans]-x));

    // Left shrine and right temple
    if (sans > 0 && tans < b) ans = min({ans, 2*(x-s[sans-1])+t[tans]-x, 2*(t[tans]-x)+x-s[sans-1]});

    // Right shrine and left temple
    if (sans < a && tans > 0) ans = min({ans, 2*(x-t[tans-1])+s[sans]-x, 2*(s[sans]-x)+x-t[tans-1]});

    cout << ans << endl;
  }
  return 0;
}
