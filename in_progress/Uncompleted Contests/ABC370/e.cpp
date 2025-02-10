#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 998244353;

int main() {
  cin.tie(0)->sync_with_stdio(false);
  
  ll n, k; cin >> n >> k;
  vector<ll> a(n), p(n+1);
  for (ll &x : a) cin >> x;
  for (int i = 0; i < n; i++) p[i+1] = (p[i] + a[i]);

  vector<ll> dp(n+1), cum_dp(n+1);
  unordered_map<ll,ll> pref_map;

  dp[0] = 1;
  pref_map[p[0]] = dp[0];
  cum_dp[0] = dp[0];
  for (int i = 1; i <= n; i++) {
    // subtract dp[j] such that p[i] - p[j] = k
    dp[i] = (cum_dp[i-1] - pref_map[p[i]-k])%MOD;
    if (dp[i] < 0) dp[i] += MOD;

    pref_map[p[i]] += dp[i];
    cum_dp[i] = (cum_dp[i-1] + dp[i])%MOD;
    pref_map[p[i]] %= MOD;
  }
  cout << dp[n] << "\n";


  return 0;
}