#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e18;

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<ll> a(n), suff(n+1);
    for (int i = 0; i < n; i++) cin >> a[i];
    suff[n] = 0;
    for (int i = n-1; i >= 0; i--) suff[i] = a[i] + suff[i+1];

    vector<ll> memo(n, -INF);
    function<ll(int)> solve = [&](int i) -> ll {
      if (i == n) return 0;
      ll &ans = memo[i];
      if (ans != -INF) return ans;
      
      ans = max(a[i]+solve(i+1)+suff[i+1], a[i]+solve(i+1));
      return ans;
    };
    cout << solve(0) << "\n";
  }

  return 0;
}