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

const int N = 2e6+5;
ll fact[N];
ll ifact[N];
const ll MOD = 1e9+7;

ll modpow(ll b, ll e) {
  ll ans = 1;
  while(e > 0) {
    if (e&1) ans = ans*b%MOD;
    e >>= 1;
    b = b*b%MOD;
  }
  return ans;
}

ll inv(ll x) {
  return modpow(x, MOD-2);
}

ll perm(ll n, ll k) {
  if (k > n) return 0;
  return fact[n]*ifact[n-k]%MOD;
}

ll comb(ll n, ll k) {
  return perm(n,k)*ifact[k]%MOD;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = i*fact[i-1]%MOD;
  ifact[N-1] = inv(fact[N-1]);
  for (int i = N-2; i >= 0; i--) ifact[i] = (i+1)*ifact[i+1]%MOD;

  ll r1, r2, c1, c2;
  cin >> r1 >> c1 >> r2 >> c2;
  ll ans = 0;
  for (ll r = r1; r <= r2; r++) {
    ans = (ans + comb(r+1+c2,c2)-comb(r+1+c1-1, c1-1))%MOD;
  }
  if (ans < 0) ans += MOD;
  cout << ans << "\n";
  
  return 0;
}
