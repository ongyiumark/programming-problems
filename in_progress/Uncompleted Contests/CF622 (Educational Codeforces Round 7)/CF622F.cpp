/*
  We know that 1^k + 2^k + ... + n^k can be expressed as a k+1 degree polynomials.
  We can find this polynomial given k+2 points.
  Look up Lagrange polynomial.

  So, if n <= k+2. We simply brute force.
  Otherwise, we use the first k+2 points to find the polynomial. 
    The points are (i, sum of powers until i).
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

const ll M = 1e9+7;
const int N = 1e6+5;
ll fact[N], ifact[N];
int n, k;

ll modpow(ll b, ll e){
  ll ans = 1;
  while (e > 0){
    if (e&1) ans = ans * b %M;
    b = b * b %M;
    e >>= 1;
  }
  return ans;
}

ll modinv(ll x){
  return modpow(x, M-2);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n >> k;
  ll ans = 0;
  if (n <= k+2){
    for (int i = 1; i <= n; i++) {
      ans += modpow(i%M, k);
      ans %= M;
    }
    cout << ans << endl;
    return 0;
  }

  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = i*fact[i-1]%M;
  ifact[N-1] = modinv(fact[N-1]);
  for (int i = N-2; i >= 0; i--) ifact[i] = (i+1)*ifact[i+1]%M;

  ll tmp = 1;
  for (int i = 1; i <= k+2; i++){
    tmp = (n-i)*tmp%M;
  }

  ll y = 1;
  for (int i = 1; i <= k+2; i++){
    ll num = tmp*modinv(n-i)%M;
    ll den = fact[i-1]*fact[k+2-i]*((k+2-i) % 2 == 0 ? 1 : -1)%M;
    ll tans = num*modinv(den)%M;
    tans = tans*y%M;

    ans += tans;
    ans %= M;
    y += modpow(i+1, k);
    y %= M;
  }
  if (ans < 0) ans += M;
  cout << ans << endl;
  
  return 0;
}
