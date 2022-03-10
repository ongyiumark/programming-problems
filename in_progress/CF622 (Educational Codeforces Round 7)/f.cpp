/*
  Start with the telescoping following sum:
    sum_{i=1}^n [(i+1)^{k+1} - i^{k+1}] = (n+1)^{k+1} - 1

  Let solve(x) denote sum_{i=1}^n (i^k).
  Then, with some algebra,
    solve(k) = [(n+1)^{k+1} - 1 - sum_{j=2}^{k+1} comb(k+1,j)*solve(k+1-j)]/comb(k+1,1)
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
const int N = 1e6+6;
ll fact[N], ifact[N];

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

ll perm(ll n, ll k){
  return fact[n]*ifact[n-k]%M;
}

ll comb(ll n, ll k){
  return perm(n, k)*ifact[k]%M;
}

ll dp[N];
ll n;

ll solve(int k){
  ll &ans = dp[k];
  if (ans != -1) return ans;
  if (k == 0) return n;
  
  ll num = modpow(n+1, k+1)-1;
  for (int i = 2; i <= k+1; i++) {
    num -= comb(k+1, i)*solve(k+1-i)%M;
  }
  num %= M;
  if (num < 0) num += M;
  return ans = num*modinv(comb(k+1,1))%M;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  /*
  int n, k; cin >> n >> k;
  ll ans = 0;
  for (int i = 1; i <= n; i++){
    ans = (ans + modpow(i,k))%M;
  }
  cout << ans << endl;
  */
  
  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = i*fact[i-1]%M;
  ifact[N-1] = modinv(fact[N-1]);
  for (int i = N-2; i >= 0; i--) ifact[i] = (i+1)*ifact[i+1]%M;

  int k; cin >> n >> k;
  memset(dp, -1, sizeof dp);
  cout << solve(k) << endl;

  
  return 0;
}
