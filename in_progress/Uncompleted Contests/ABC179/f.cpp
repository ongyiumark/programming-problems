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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, q; cin >> n >> q;
  vector<ll> min_v(n, n), min_h(n, n);

  ll ans = 0;
  while(q--) {
    ll t, x; cin >> t >> x;
    if (t == 1) {
      ans += min_h[x]-2;

      // update min_v[1..min_h[x]-1] w/ x
    }
    else {
      ans += min_v[x]-2;
      
      // update min_h[1..min_v[x]-1] w/ x
    }
  }

  cout << (n-2)*(n-2)-ans << "\n";
  
  return 0;
}
