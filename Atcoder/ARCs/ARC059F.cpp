/*
  Realize that the contents of the string s doesn't actually matter.
  Let m be the length of s. We can simply count the number of ways to end up with a string of length m.
  Then, divide by the 2^m.
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

int n, m;
string s;

const ll MOD = 1e9+7;
const int N = 5005;
ll dp[N][N];

ll modpow(ll b, ll e){
  ll ans = 1;
  while (e > 0){
    if (e&1) ans = b*ans%MOD;
    e >>= 1;
    b = b*b % MOD;
  }
  return ans;
}

ll modinv(ll x){
  return modpow(x, MOD-2);
}

ll solve(int moves, int sz){
  ll &ans = dp[moves][sz];
  if (ans != -1) return ans;
  if (moves == 0) {
    if (sz == m) return ans = 1;
    return ans = 0;
  }

  ans = 0;
  // press 0
  ans  = (ans + solve(moves-1, sz+1))%MOD;
  // press 1
  ans  = (ans + solve(moves-1, sz+1))%MOD;
  // press back
  ans = (ans + solve(moves-1, max(sz-1,0)))%MOD;

  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n >> s;
  m = s.size();
  memset(dp, -1, sizeof dp);
  ll ans = solve(n,0);
  cout << (ans*modinv(modpow(2,m)))%MOD << endl;
  return 0;
}
