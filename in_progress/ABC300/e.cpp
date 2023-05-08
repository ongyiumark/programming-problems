#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll MOD = 998244353;
ll modpow(ll b, ll e) {
  ll ans = 1;
  while (e > 0) {
    if (e&1) ans = ans*b%MOD;
    b = b*b %MOD;
    e >>= 1;
  } 
  return ans;
}

ll inv(ll n) {
  return modpow(n, MOD-2);
}

ll N;
map<ll,ll> memo;
ll solve(ll n) {
  if (memo.count(n) > 0) return memo[n];

  ll &res = memo[n];
  res = 0;
  if (n == N) return res = 1;
  else if (n > N) return res = 0;

  for (int i = 2; i <= 6; i++) {
    res += solve(i*n);
    res %= MOD;
  }
  res *= inv(5);
  res %= MOD;
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> N;
  cout << solve(1) << "\n";
  return 0;
}
