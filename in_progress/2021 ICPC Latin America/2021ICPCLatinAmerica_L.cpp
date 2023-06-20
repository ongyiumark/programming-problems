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

const ll MOD = 1e9+7;
const int N = 2e6+5;

ll get_happiness(ll N, ll pairs, ll singles, ll I, ll E) {
  ll h = pairs*2 + singles;
  ll empty = N - pairs - singles;

  // process extroverts
  // fill singles
  ll tmp = min(singles, E);
  singles -= tmp; E -= tmp; pairs += tmp; h += tmp; 
  if (singles == 0 and empty == 0) return h;

  // fill empty seats
  ll single_extrovert = 0;
  if (E > 0) {
    tmp = min(2*empty, E);
    if (tmp == 2*empty) return h + tmp;
    h += tmp - (E%2); E -= tmp; empty -= (tmp+1)/2; pairs += tmp/2; single_extrovert += (tmp%2);
  }

  // process introverts
  ll single_introvert = 0;
  tmp = min(empty, I);
  I -= tmp; empty -= tmp; single_introvert += tmp; h += tmp;

  // sit next to extrovert/easygoing
  tmp = min(singles, I);
  I -= tmp; singles -= tmp;

  if (single_extrovert > 0) {
    tmp = min(single_extrovert, I);
    I -= tmp; single_extrovert -= tmp;
    h += tmp;
  }
  
  // subtract excess
  h -= min(single_introvert, I);
  return h;
}

ll modpow(ll b, ll e) {
  ll ans = 1;
  while (e > 0) {
    if (e&1) ans = ans*b%MOD;
    b = b*b%MOD;
    e >>= 1;
  }
  return ans;
}

ll modinv(ll x) {
  return modpow(x, MOD-2);
}

ll fact[N], ifact[N];
void initialize() {
  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = i*fact[i-1]%MOD;
  ifact[N-1] = modinv(fact[N-1]);
  for (int i = N-2; i >= 0; i--) ifact[i] = (i+1)*ifact[i+1]%MOD;
}

ll perm(ll n, ll k) {
  return fact[n]*ifact[n-k]%MOD;
}

ll comb(ll n, ll k) {
  return perm(n, k)*ifact[k]%MOD;
}

ll prob(ll pairs, ll singles, ll N) {
  ll G = 2*pairs + singles;
  return comb(N, pairs)*comb(N-pairs, singles)%MOD*modpow(2, singles)%MOD;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  initialize();

  ll N, G, I, E; cin >> N >> G >> I >> E;
  if (G >= 2*N) {
    cout << 2*N << "\n";
    return 0;
  }

  ll ans = 0;
  for (ll pairs = 0; 2*pairs <= G; pairs++) {
    ll singles = G - 2*pairs;
    if (singles + pairs > N) continue;
    ll p = prob(pairs, singles, N);
    ll h = get_happiness(N, pairs, singles, I, E);

    ans += p*h%MOD;
    ans %= MOD;
  }
  ans *= modinv(comb(2*N, G));
  ans %= MOD;

  cout << ans << "\n";

  return 0;
}
