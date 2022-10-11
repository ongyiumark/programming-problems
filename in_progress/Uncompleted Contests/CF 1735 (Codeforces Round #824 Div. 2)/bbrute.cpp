#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ll,ll> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void testcase() {
  int n; cin >> n;
  ll a[n]; 
  for (int i = 0; i < n; i++) cin >> a[i];
  if (n == 1) {
    cout << 0 << endl;
    return;
  }
  
  map<ll, ll> b;
  for (int i = 0; i < n; i++) b[a[i]] = 1;
  ll ans = 0;
  ll step = 0;
  do {
    map<ll, ll> tmp;
    int sz = b.size();
    if (sz <= 1 || ((--b.end())->first) < 2*(b.begin()->first)) {
      //cout << step << " " << b.begin()->first << " " << (--b.end())->first << endl;
      break;
    }
    ll x = b.begin()->first;
    for (auto it = b.begin(); it != b.end(); it++) {
      ll y = it->first;
      //cout << step << " " << x << " " << y << endl;

      ll lo = 0;
      ll hi = 1e9;
      ll k = 0;
      while(lo <= hi) {
        ll mid = hi - (hi-lo)/2;
        ll ny = y-(2*x-1)*mid;
        if (2*ny + 2 > 5*x) {
          k = mid;
          lo = mid+1;
        }
        else hi = mid-1;
      }
      tmp[2*x-1] += k*(it->second);
      ans += k;
      y -= (2*x-1)*k;
      if (2*x <= y) {
        tmp[(y+1)/2] += 1;
        tmp[y/2] += 1;
        ans += 1;
      }
      else {
        tmp[y] += 1;
      }
    }
    tmp[x] += b.begin()->second;
    swap(tmp,b);
    step++;
  } while(true);

  cout << ans << "\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while(t--) testcase(); 
  return 0;
}
