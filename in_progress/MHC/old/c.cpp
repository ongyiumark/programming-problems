#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll check(vector<ll> &a, ll k) {
  int m = a.size();
  unordered_map<ll, int> cnt;
  int unpaired = 0;
  for (int i = 0; i < m; i++) {
    if (a[i] >= k) return -1;
    ll partner = k-a[i];
    if (cnt.find(partner) == cnt.end()) {
      unpaired++;
      cnt[a[i]] += 1;
    }
    else {
      unpaired--;
      cnt[partner] -= 1;
      if (cnt[partner] == 0) {
        cnt.erase(partner);
      }
    }
  }

  if (unpaired > 1) return -1;
  return (k-cnt.begin()->first);
}

void testcase() {
  int n; cin >> n;
  vector<ll> a(2*n-1);
  for (ll &x : a) cin >> x;

  sort(a.begin(), a.end());
  if (n == 1) {
    cout << 1 << "\n";
    return;
  }

  vector<ll> candidates = {a[0]+a[2*n-2], a[0]+a[2*n-3], a[1]+a[2*n-2]};
  ll ans = 1e18;
  for (ll k : candidates) {
    ll val = check(a, k);
    if (val != -1) {
      ans = min(val, ans);
    }
  }

  if (ans == 1e18) cout << -1 << "\n";
  else cout << ans << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int t; cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    cout << "Case #" << tt << ": ";
    testcase();
  }
  return 0;
}