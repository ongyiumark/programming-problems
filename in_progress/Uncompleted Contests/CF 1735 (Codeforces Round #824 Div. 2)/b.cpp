#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
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

  ll x = a[0];
  ll ans = 0;
  for (int i = 1; i < n; i++) {
    ll y = a[i];
    ll m = 2*x-1;
    ll k = (y+m-1)/m-1;
    ans += k;
    //cout << x << " " << y << " " << k << endl;
  }

  cout << ans << "\n";
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while(t--) testcase(); 
  return 0;
}
