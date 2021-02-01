#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5+1;
const int MOD = 1e9+7;

ll A[N];
ll prefix[N];

ll range_sum(int l, int r){
  if (l == 0) return prefix[r];
  return prefix[r] - prefix[l-1];
}

ll fact[N];
ll ifact[N];

ll modpow(ll b, ll e){
  ll ans = 1;
  while(e > 0){
    if (e&1) ans = ans*b % MOD;
    b = b*b % MOD;
    e >>= 1;
  }
  return ans;
}

ll inv(ll x){
  return modpow(x, MOD-2);
}

ll perm(ll n, ll k){
  return fact[n]*ifact[n-k]%MOD;
}

ll comb(ll n, ll k){
  return perm(n,k)*ifact[k]%MOD;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  fact[0] = 1;
  for (int i = 1; i < N; i++){
    fact[i] = i*fact[i-1]%MOD;
  }
  ifact[N-1] = inv(fact[N-1]);
  for (int i = N-2; i >= 0; i--){
    ifact[i] = (i+1)*ifact[i+1]%MOD;
  } 

  int n, k; cin >> n >> k;

  for (int i = 0; i < n; i++)
    cin >> A[i];

  if (k == 1) {
    cout << 0 << endl;
    return 0;
  }

  sort(A, A+n);

  prefix[0] = A[0];
  for (int i = 1; i < n; i++){
    prefix[i] = (prefix[i-1]+A[i])%MOD;
  }

  ll ans = 0;
  for (int i = k-2; i <= n-2; i++){
    ll temp = range_sum(i+1, n-1)-range_sum(0, n-i-2);
    temp = temp * comb(i, k-2) % MOD;
    ans = (ans + temp) % MOD;
  }
  cout << ans << endl;
  return 0;
}
