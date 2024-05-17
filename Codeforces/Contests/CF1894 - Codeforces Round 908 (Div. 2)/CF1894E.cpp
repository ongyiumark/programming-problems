#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int t; cin >> t;
  while (t--) {
    int m; cin >> m;

    vector<ll> n(m), l(m), r(m), acnt(m);
    vector<vector<ll>> a(m), c(m);

    ll total_n = 0, total_l = 0, total_r = 0;
    for (int i = 0; i < m; i++) {
      cin >> n[i] >> l[i] >> r[i];
      total_n += n[i];
      total_l += l[i];
      total_r += r[i];
      a[i].resize(n[i]); c[i].resize(n[i]);
      for (int j = 0; j < n[i]; j++) cin >> a[i][j];
      for (int j = 0; j < n[i]; j++) {
        cin >> c[i][j];
        acnt[i] += c[i][j];
      }
    }

    if (total_r - total_l + 1 > total_n) {
      cout << 0 << "\n";
      continue;
    }

    map<ll,ll> nums, cnt;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n[i]; j++) {
        ll forced_take = max(r[i]-(acnt[i]-c[i][j]),0LL);
        nums[a[i][j]] += min(forced_take, r[i]-l[i]);
        cnt[a[i][j]] += forced_take;
      }
    }
    ll ans = 1e18;
    for (ll i = total_l; i <= total_r; i++) {
      ll res = cnt[i]-min(total_r-i, nums[i]);
      ans = min(ans, res);
    }
    cout << ans << "\n";
  }
  return 0;
}