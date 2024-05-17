#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e9+7;
const int N = 1e5+5;
int main() {
  cin.tie(0)->sync_with_stdio(0);

  vector memo(N, vector(10, vector(2, -1LL)));
  int t; cin >> t;

  function<ll(int,int,bool)> solve = [&](int i, int prev, bool flag) -> ll  {
    ll &ans = memo[i][prev][flag];
    if (ans != -1) return ans;
    if (i == 0) return ans = 1;

    ans = 0;
    if (!flag) {
      for (int j = prev; j >= 0; j--) ans += solve(i-1, j, flag);
      if (prev+1 < 10) ans += solve(i, prev+1, !flag);
      ans %= MOD;
      return ans;
    }

    for (int j = prev; j < 10; j++) ans += solve(i-1, j, flag);
    ans %= MOD;
    return ans;
  };

  while(t--) {
    int n; cin >> n;
    cout << solve(n, 9, 0) << "\n";
  }
  return 0;
}