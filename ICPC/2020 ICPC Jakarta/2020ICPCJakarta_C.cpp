#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,ll> edge;
typedef pair<ll,ll> pll;

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int n; cin >> n;
  vector<vector<edge>> adj(n);
  vector<int> deg(n);
  for (int i = 0; i < n-1; i++) {
    int u, v, w; cin >> u >> v >> w;
    u--; v--;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
    deg[u]++; deg[v]++;
  }

  vector memo(n, vector(2, -1LL));
  function<ll(int,int,int)> solve = [&](int u, bool include, int p) {  
    ll &ans = memo[u][include];
    if (ans != -1) return ans;

    ans = 0;
    vector<pll> results; 
    for (auto &[v, w] : adj[u]) {
      if (v == p) continue;
      results.push_back({solve(v, 0, u), solve(v, 1, u)+w});
    }
    if (results.size() == 0) return ans;
    sort(results.begin(), results.end(), [&](const pll& left, const pll& right){
      return left.second-left.first > right.second-right.first;
    });

    ll total_not_include = 0;
    for (auto &[a, b] : results) total_not_include += a;
    ll total_include = 0;

    if (include) {
      total_include += results[0].second;
      total_not_include -= results[0].first;
    }

    int sz = results.size();
    for (int i = include; i <= sz; i+=2) {
      ans = max(ans, total_include+total_not_include);
      if (i+1 < sz) {
        total_include += (results[i].second + results[i+1].second);
        total_not_include -= (results[i].first + results[i+1].first);
      }
    }
    return ans;
  };

  ll ans = solve(0,0,-1);
  if (deg[0] == 1) ans = max(ans, solve(0,1,-1));
  cout << ans << "\n";

  return 0;
}