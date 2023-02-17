#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e6+5;
const int MOD = 1e9+7;


ll fact[N];
ll ifact[N];

ll modpow(ll b, ll e) {
  ll ans = 1;
  while (e > 0) {
    if (e&1) ans = ans*b % MOD;
    b = b*b%MOD;
    e >>= 1;
  }

  return ans;
}

ll inv(ll x) {
  return modpow(x, MOD-2);
}

ll perm(ll n, ll k) {
  return fact[n]*ifact[n-k] % MOD;
}

ll comb(ll n, ll k) {
  return perm(n, k)*ifact[k] %MOD;
}

ll solve(ll r, ll c) {
  return comb(r+c, c);
}
int main(){
  ll r1, r2, c1, c2; cin >> r1 >> c1 >> r2 >> c2;

  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = i*fact[i-1] % MOD;
  ifact[N-1] = inv(fact[N-1]);

  for (int i = N-2; i >= 0; i--) {
    ifact[i] = (i+1)*ifact[i+1] % MOD;
  }


  ll ans = 0;
  for (int c = c1; c <= c2; c++) {
    ans = (ans + solve(r2, c+1) - solve(r1-1, c+1))%MOD;
  }
  if (ans < 0) ans += MOD;
  
  cout << ans << "\n";

}
