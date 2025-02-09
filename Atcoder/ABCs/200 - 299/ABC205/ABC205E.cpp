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

const int MAX_N = 2e6+5;
const ll MOD = 1e9+7;
vector<ll> fact(MAX_N), ifact(MAX_N);

ll modpow(ll b, ll e, ll m = MOD) {
  ll ans = 1;
  while (e > 0) {
    if(e&1) ans = ans*b%m;
    b = b*b%m;
    e >>= 1;
  }
  return ans;
}

ll modinv(ll x, ll m = MOD) { return modpow(x, m-2, m); }

void init_fact(int n = MAX_N, ll m = MOD) {
  fact[0] = 1;
  for (int i = 1; i < n; i++) fact[i] = i*fact[i-1]%m;
  ifact[n-1] = modinv(fact[n-1], m);
  for (int i = n-2; i >= 0; i--) ifact[i] = (i+1)*ifact[i+1]%m;
}

ll perm(ll n, ll k, ll m = MOD) { return k <= n ? fact[n]*ifact[n-k]%m : 0; }
ll comb(ll n, ll k, ll m = MOD) { return perm(n,k,m)*ifact[k]%m; }

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  init_fact();

  ll n, m, k; cin >> n >> m >> k;
  if (n > m + k) {
    cout << 0 << "\n";
    return 0;
  }

  ll ans = comb(n+m, m) - comb(n+m, m+k+1);
  ans %= MOD;
  if (ans < 0) ans += MOD;
  cout << ans << "\n";

  return 0;
}
