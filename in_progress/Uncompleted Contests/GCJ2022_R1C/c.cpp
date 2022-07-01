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

const ll MOD = 1e9+7;
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

ll prob(ll p, ll q) {
  return p*modinv(q)%MOD;
}

const int N = 1e5;
ll fact[N];
ll ifact[N];

ll perm(ll n, ll k) {
  return fact[n]*ifact[n-k]%MOD;
}

ll comb(ll n, ll k) {
  return perm(n,k)*ifact[k]%MOD;
}

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

void testcase(){
  ll m, k; cin >> m >> k;

  ll p = comb(5,2)*comb(3,2)*fact[8]%MOD;
  ll q = fact[m*(m-1)/2];
  ll g = gcd(p,q);
  
  cout << p << " " << q << endl;
  cout << prob(p/g,q/g) << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = i*fact[i-1]%MOD;
  }
  ifact[N-1] = modinv(fact[N-1]);
  for (int i = N-2; i >= 0; i--) {
    ifact[i] = (i+1)*ifact[i+1]%MOD;
  }
  


  int t; cin >> t;
  for (int x = 1; x <= t; x++) {
    cout << "Case #" << x << ": ";
    testcase();
  }
  
  return 0;
}
