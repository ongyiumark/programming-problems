/*
  First thing to notice is that we can solve for the X-component and the Y-component separately.
  Then, notice that we can fix two pieces, and this distance will repeat (M*N-2)C(K-2) times.
    We don't care about the other distances because they will be counted when we 
    go through all the permutations of the two pieces.

  The problem is reduced to the sum of the distance of two pieces in a 1D line.
  We can fix the distance then count how many ways we can have that distance.
  We end up with sum d=1:N-1 of d*(N-d)*M*M.
    The M*M is there to account for the different ways the two pieces can go in the hidden dimension.
    We can use algebra to simplify this further, but this should be enough to pass the test cases.
  
  We do a similar calculation for M, and add the sums for the final answer.
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

const ll MOD = 1e9+7;
const int N = 2e5+5;

ll fact[N];
ll ifact[N];

ll perm(ll n, ll k){
  if (n < k) return 0;
  return fact[n]*ifact[n-k]%MOD;
}

ll comb(ll n, ll k){
  return perm(n,k)*ifact[k]%MOD;
}

ll modpow(ll b, ll e){
  ll ans = 1;
  while(e > 0){
    if (e&1) ans = ans*b%MOD;
    e >>= 1;
    b = b*b%MOD;
  }
  return ans;
}

ll modinv(ll x){
  return modpow(x, MOD-2);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll n, m, k; cin >> n >> m >> k;

  fact[0] = 1;
  for (int i = 1; i < N; i++){
    fact[i] = i*fact[i-1]%MOD;
  }
  ifact[N-1] = modinv(fact[N-1]);
  for (int i = N-2; i >= 0; i--){
    ifact[i] = (i+1)*ifact[i+1]%MOD;
  }

  ll ansN = (n-1)*n*(n+1)%MOD;
  ll ansM = (m-1)*m*(m+1)%MOD;
  ansN = ansN * m % MOD;
  ansN = ansN * m % MOD;
  ansM = ansM * n % MOD;
  ansM = ansM * n % MOD;
  ll ans = (ansM + ansN)%MOD;
  ans = ans * modinv(6) %MOD;
  ans = ans * comb(m*n-2, k-2) %MOD;
  cout << ans << endl;
  return 0;
}
