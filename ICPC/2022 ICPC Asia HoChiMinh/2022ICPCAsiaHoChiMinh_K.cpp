#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll INF = 1e12;
int main() {
  cin.tie(0)->sync_with_stdio(false);

  ll n, k; cin >> n >> k;
  vector<ll> a(n);
  for (ll &x : a) cin >> x;
  vector adj(n, vector<int>());
  for (int i = 0; i < n-1; i++) {
    int u, v; cin >> u >> v; 
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  function<pair<ll,ll>(ll,int,int)> count_paths = [&](ll threshold, int u, int p) -> pair<ll,ll> {
    vector<ll> unmatched;
    ll cnt = 0; 
    unmatched.push_back(a[u]);
    for (int &v : adj[u]) {
      if (v == p) continue;
      const auto &[v_cnt, min_unmatched] = count_paths(threshold, v, u);
      cnt += v_cnt;
      unmatched.push_back(min_unmatched);
    }
    sort(unmatched.begin(), unmatched.end());
    if (unmatched.size() == 1) return {cnt, unmatched[0]};
    else if (unmatched[0] + unmatched[1] <= threshold) return {cnt+1, INF};
    else return {cnt, unmatched[0]};
  };

  ll lo = 0;
  ll hi = 1e11;
  ll ans = -1;
  while (lo <= hi) {
    ll mid = hi - (hi-lo)/2;
    const auto &[cnt, min_unmatched] = count_paths(mid, 0, -1);
    if (cnt >= k) {
      ans = mid;
      hi = mid-1;
    }
    else lo = mid+1;
  }
  cout << ans << "\n";
}