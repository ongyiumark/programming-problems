#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0)->sync_with_stdio(false);
  
  int n, q; cin >> n >> q;
  vector<ll> a(n);
  for (ll &x : a) cin >> x;
  while (q--) {
    ll k; cin >> k;
    for (int j = 60; j >= 0; j--) {
      ll need = 0;
      for (int i = 0; i < n; i++) {
        if ((a[i]>>j)&1) continue;
        need += 1;
      }

      __int128 required = __int128(1LL<<j)*need;
      if (required > k) continue;

      for (int i = 0; i < n; i++) {
        a[i] |= 1;
      }
      k -= required;
    }

    ll ans = (1LL<<60)-1;
    for (int i = 0; i < n; i++) ans &= a[i];
    cout << ans << "\n";
  }
  
  return 0;
}