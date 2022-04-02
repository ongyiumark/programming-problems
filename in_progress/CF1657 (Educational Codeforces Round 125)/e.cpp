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

const ll M = 998244353;
ll modpow(ll b, ll e){
  ll ans = 1;
  while(e > 0){
    if (e&1) ans = ans*b%M;
    b = b*b%M;
    e >>= 1;
  }
  return ans;
}

ll modinv(ll x){
  return modpow(x, M-2);
}

const int N = 300;
ll fact[N];
ll ifact[N];

ll perm(ll n, ll k){
  if (n < k) return 0;
  return fact[n]*ifact[n-k]%M;
}
ll comb(ll n, ll k){
  return perm(n,k)*ifact[k]%M;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = i*fact[i-1]%M;
  ifact[N-1] = modinv(fact[N-1]);
  for (int i = N-2; i >= 0; i--) ifact[i] = ifact[i+1]*(i+1)%M;

  ll n, k; cin >> n >> k;
  if (n == 2) {
    cout << k << endl;
    return 0;
  }

  ll ans = modpow(k,n*(n-1)/2 - (n-1));
  for (int i = 2; i <= k; i++){
    for (int j = 1; j <= n-1; j++) {
      // Make n-1-j edges from 1 to be less than i. 
      // This means that j edges are i.
      ll tmp = modpow(i-1,n-1-j)%M;
      for (int l = 0; l < j; l++) {
        // WLOG assume 2 to j+1 are the edges that have i
        tmp *= comb(n-2,j-1)*modpow(k, n-2-j+1)%M;
        tmp %= M;
      } 
      for (int l = j; l < n; l++) {
        tmp *= comb(n-2,j)*modpow(k, n-2-j)%M;
        tmp %= M;
      }


      tmp = tmp*comb(n-1,j)%M;
      ans += tmp;
      ans %= M;
    }
  } 
  if (ans < 0) ans += M;
  cout << ans << endl;
  return 0;
}
