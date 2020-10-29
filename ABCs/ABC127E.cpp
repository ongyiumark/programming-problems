/*
  Solve for x and y independently.
  Fix 2 cells. This will be counted (NM-2)C(K-2) times.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5;
const int MOD = 1e9+7;

ll fact[N];
ll ifact[N];

ll perm(int n, int k){
  return fact[n]*ifact[n-k]%MOD;
}

ll comb(int n, int k){
  return perm(n,k)*ifact[k]%MOD;
}

ll modpow(ll b, ll e){
  ll ans = 1;
  while(e > 0){
    if (e&1) ans = ans*b%MOD;
    b = b*b%MOD;
    e >>= 1;
  }
  return ans;
}

ll inv(ll x){
  return modpow(x, MOD-2);
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

  ll n, m, k;
  cin >> n >> m >> k;

  ll ans = m*n;
  ans = ans*(m*n-1)%MOD;
  ans = ans*(m+n)%MOD;
  ans = ans*inv(6)%MOD;
  ans = ans*comb(m*n-2, k-2)%MOD;

  cout << ans << "\n";
  return 0;
}
