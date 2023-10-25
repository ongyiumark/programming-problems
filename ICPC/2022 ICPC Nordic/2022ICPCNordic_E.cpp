#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1e9;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m; cin >> n >> m;
  vector adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> shortest_cycle(n);
  function<int(int)> get_shortest = [&](int s) {
    queue<int> q;
    
    vector<int> depth(n, -1);
    vector<int> par(n, -1);
    depth[s] = 0; q.push(s);

    int ans = INF;
    while(!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : adj[u]) {
        if (par[u] == v) continue;
        if (depth[v] >= 0) {
          if (depth[u] + depth[v] + 1 >= ans) continue;
          ans = min(ans, depth[u] + depth[v] + 1);
          continue;
        }
        depth[v] = depth[u]+1;
        par[v] = u;
        q.push(v);
      }
    }
    return ans;
  };
  for (int i = 0; i < n; i++) shortest_cycle[i] = get_shortest(i);
  int shortest = INF;
  for (int i = 0; i < n; i++) shortest = min(shortest, shortest_cycle[i]);

  vector<int> to_ignore(n);
  function<ll(int,int)> count_cycles = [&](int s, int l) {
    queue<int> q;
    
    vector<int> depth(n, -1);
    depth[s] = 0; q.push(s);

    while(!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : adj[u]) {
        if (depth[v] >= 0) continue;
        if (to_ignore[v]) continue;
        depth[v] = depth[u]+1;
        q.push(v);
      }
    }

    ll cnt = 0;
    if (l % 2 == 1) {
      for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
          if (depth[v] == (l-1)/2 && depth[u] == (l-1)/2) {
            cnt++;
          }
        }
      }
      return cnt/2;
    }

    vector<ll> memo(n, -1);
    function<ll(int)> count_paths = [&](int v) {
      ll &ans = memo[v];
      if (ans != -1) return ans;

      ans = 0;
      if (v == s) return ans = 1;
      for (int u : adj[v]) {
        if (depth[v] != depth[u]+1) continue; // shortest paths only
        ans += count_paths(u);
      } 
      return ans;
    };
    for (int u = 0; u < n; u++) {
      if (depth[u] == l/2) {
        ll tmp = count_paths(u);
        cnt += tmp*(tmp-1)/2;
      }
    }

    return cnt;
  };

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (shortest == shortest_cycle[i]) {
      ans += count_cycles(i, shortest);
      to_ignore[i] = true;
    }
  } 
  cout << ans << "\n";
  return 0;
}