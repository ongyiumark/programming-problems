/*
  Count the number of ways from 
    (1,1) to (h-a,i) and (h-a+1,i) to (h,w)
  where b+1 <= i <= w.
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
const ll MOD = 1e9+7;
vector<ll> fact(N), ifact(N);

ll perm(ll n, ll k) {
  if (n < k) return 0;
  return fact[n]*ifact[n-k]%MOD;
}

ll comb(ll n, ll k) {
  return perm(n,k)*ifact[k]%MOD;
}

ll modpow(ll b, ll e) {
  ll ans = 1;
  while(e > 0) {
    if (e&1) ans = ans*b%MOD;
    b = b*b%MOD;
    e >>= 1;
  } 
  return ans;
}

ll inv(ll x) {
  return modpow(x, MOD-2);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = i*fact[i-1]%MOD;
  ifact[N-1] = inv(fact[N-1]);
  for (int i = N-2; i >= 0; i--) ifact[i] = (i+1)*ifact[i+1]%MOD;

  int h, w, a, b; cin >> h >> w >> a >> b;
  ll ans = 0;
  for (int i = b+1; i <= w; i++) {
    // (1,1) to (h-a,i) times (h-a+1,i) to (h,w)
    ans += comb(h-a+i-2,i-1)*comb(a+(w-i)+1-2, (w-i)+1-1)%MOD;
    ans %= MOD;
  }
  cout << ans << endl;

  return 0;
}
