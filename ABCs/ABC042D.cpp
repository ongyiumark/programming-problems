#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5+1;
const int MOD = 1e9+7;
ll fact[N];
ll ifact[N];

ll modpow(ll b, ll e){
  ll ans = 1;
  while (e > 0){
    if (e&1) ans = ans*b%MOD;
    b = b*b%MOD;
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
  if (n < k) swap(n, k);
  return perm(n,k)*ifact[k]%MOD;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = i*fact[i-1]%MOD;
  ifact[N-1] = inv(fact[N-1]);
  for (int i = N-2; i >= 0; i--) ifact[i] = (i+1)*ifact[i+1]%MOD;

  int h, w, a, b;
  cin >> h >> w >> a >> b;

  ll ans = 0;
  for (int j = b; j < w; j++){
    ll curr = comb(h-a-1+j, j)*comb(a-1+w-j-1, a-1)%MOD;
    ans = (ans + curr)%MOD;
  }

  cout << ans << endl;
  return 0;
}
