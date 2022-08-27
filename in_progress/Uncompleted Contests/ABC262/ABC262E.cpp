/*
  Consider the sum of degrees of the red vertices, denoted by S. 
    Red-red edges will be counted twice, but red-blue edges are counted once.
    Thus red-blue edges are even iff the S is even.
  We count the number of vertices with odd and even degree.
  We can then fix the number of odd-degree red vertices, and count with combinatorics.
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

const int N = 2e5+5;
const ll MOD = 998244353;
int deg[N];
ll fact[N], ifact[N];

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

ll perm(ll n, ll k) {
  return fact[n]*ifact[n-k]%MOD;
}

ll comb(ll n, ll k) {
  return perm(n,k)*ifact[k]%MOD;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(deg, 0, sizeof deg);
  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = i*fact[i-1]%MOD;
  ifact[N-1] = modinv(fact[N-1]);
  for (int i = N-2; i >= 0; i--) ifact[i] = (i+1)*ifact[i+1]%MOD;

  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    u--; v--;
    deg[u]++; deg[v]++;
  }

  int odds = 0, evens = 0;
  for (int i = 0; i < n; i++) {
    if (deg[i]%2 == 0) evens++;
    else odds++;
  }

  ll res = 0;
  for (int i = 0; i <= min(odds,k); i+=2) {
    if (k-i > evens) continue;
    res += comb(odds,i)*comb(evens,k-i);
    res %= MOD;
  }
  cout << res << endl;
  return 0;
}
