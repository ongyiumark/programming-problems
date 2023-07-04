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

ll MOD = 1e9+7;
const int N = 1e6;

ll modpow(ll b, ll e) {
  ll ans = 1;
  while(e > 0) {
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
ll perm(ll n, ll k) {
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
  ifact[N-1] = modinv(fact[N-1]);
  for (int i = N-2; i >= 0; i--) ifact[i] = (i+1)*ifact[i+1]%MOD;
  
  // Let k be the number of A[i] = B[i] 
  // perm(M, n)**2 - all perms
  // perm(M, 1) * perm(M-1, N-1)**2 - subtract perms with 1 equal
  // perm(M, 2) * perm(M-2, N-2)**2 - add perms with 2 equal

  int n, m; cin >> n >> m;
  ll ans = 0;
  ll mult = 1;
  for (int k = 0; k <= n; k++) {
    ll tmp = comb(n, k)*perm(m, k)%MOD;
    tmp = tmp*perm(m-k, n-k)%MOD; 
    tmp = tmp*perm(m-k, n-k)%MOD; 

    ans = (ans + mult*tmp%MOD)%MOD;
    if (ans < 0) ans += MOD;
    mult *= -1;
  }
  cout << ans << "\n";


  return 0;
}
