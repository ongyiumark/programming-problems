#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 2019;

int main() {
  cin.tie(0)->sync_with_stdio(false);

  ll L, R; cin >> L >> R;
  ll ans = 4e18;
  for (ll i = L; i <= min(R, L+2020); i++) {
    for (ll j = i+1; j <= min(R, L+2020); j++) {
      ans = min(ans, i*j%MOD);
    }
  }
  cout << ans << "\n";
  return 0;
}