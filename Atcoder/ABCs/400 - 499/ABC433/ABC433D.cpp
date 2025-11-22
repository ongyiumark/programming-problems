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
  cin.tie(0)->sync_with_stdio(false);
  
  ll n, m; cin >> n >> m;
  vector<ll> a(n);
  for (ll &x : a) cin >> x;

  // f(a_i, a_j) % m = 0
  // (a_i * 10**len(a_j) + a_j) % m = 0
  // a_j % m = -a_i * 10**len(a_j) % m 
  vector<ll> pow10(11);
  pow10[0] = 1%m;
  for (int i = 1; i <= 10; i++) {
    pow10[i] = pow10[i-1]*10%m;
  }

  vector<unordered_map<ll,ll>> mod_count(11);
  // mod_count[k][x] -> count if -a_i * 10**k % m = x
  for (int i = 0; i < n; i++) {
    ll curr_mod = -a[i]%m;
    if (curr_mod < 0) curr_mod += m;
    
    mod_count[0][curr_mod] = mod_count[0][curr_mod] + 1;
    for (int k = 1; k <= 10; k++) {
      curr_mod = curr_mod*10%m;
      mod_count[k][curr_mod] = mod_count[k][curr_mod] + 1;
    }
  }

  ll ans = 0;

  for (int i = 0; i < n; i++) {
    // k = length of i
    ll top = 1;
    int k = 0;
    while (a[i] >= top) {
      k++;
      top *= 10;
    }

    ans += mod_count[k][a[i]%m];
  }
  cout << ans << "\n";
  return 0;
}
