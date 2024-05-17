#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll LG = 55;
map<ll, ll> memo;
ll solve(ll x) {
  if (memo.find(x) != memo.end()) return memo[x];

  ll &ans = memo[x];
  if (x == 0) return ans = 0;
  if (x == 1) return ans = 1;
  int k;
  for (k = LG; ((1LL<<k)&x) == 0; k--);

  return ans = solve((1LL<<k)-1) + (x-(1LL<<k)+1) + solve(x^(1LL<<k));
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;
  while (t--) {
    ll a, b; cin >> a >> b;
    if (a > b) swap(a, b);
    cout << solve(b)-solve(a-1) << "\n";
  }


  return 0;
}