/*
  Each a_i can be written as a product of the prime factors of m.
  So, we can first prime factorize m. Then, handle each prime separately.

  How many ways can we write the multiplicity of prime p with n whole numbers?
    Stars and bars.
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

ll n, m;
const ll MOD = 1e9+7;
const int N = 1e5+70;
ll fact[N], ifact[N];

ll modpow(ll b, ll e){
  ll ans = 1;
  while(e > 0){
    if (e&1) ans = ans*b%MOD;
    b = b*b%MOD;
    e >>= 1;
  }
  return ans;
}

ll modinv(ll x){
  return modpow(x,MOD-2);
}

ll perm(ll n, ll k){
  return fact[n]*ifact[n-k]%MOD;
}

ll comb(ll n, ll k){
  return perm(n,k)*ifact[k]%MOD;
}

ll boxitems(ll n, ll k){
  return comb(n-1+k, k);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  map<int,int> factors;
  for (ll d = 2; d*d <= m; d++){
    while(m % d == 0){
      m /= d;
      factors[d]++;
    }
  }
  if (m > 1) factors[m]++;

  fact[0] = 1;
  for (int i = 1; i < N; i++){
    fact[i] = i*fact[i-1]%MOD;
  }
  ifact[N-1] = modinv(fact[N-1]);
  for (int i = N-2; i >= 0; i--){
    ifact[i] = (i+1)*ifact[i+1]%MOD;
  }

  ll ans = 1;
  for(auto it : factors){
    ans = ans*boxitems(n, it.second)%MOD;
  }
  cout << ans << endl;
  return 0;
}
