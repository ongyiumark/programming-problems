#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge {
  int u, v;
  Edge(int u, int v) : u(u), v(v) {}
  Edge reverse() const { return Edge(v, u); }
  friend ostream& operator<<(ostream &os, Edge &e);
};


ostream& operator<<(ostream& os, Edge &e) {
  os << e.u << " - " << e.v;
  return os;
}

vector<bool> find_bridges(vector<Edge> &edges, int n) {
  vector<bool> vis(n), result(edges.size());
  vector<int> tin(n, -1), low(n, -1);

  vector<vector<pair<int,int>>> adj(n);
  for (int i = 0; i < edges.size(); i++) {
    Edge &e = edges[i];
    adj[e.u].emplace_back(e.v, i);
    adj[e.v].emplace_back(e.u, i);
  }

  int timer = 0;
  function<void(int, int)> dfs = [&](int u, int p) {
    tin[u] = low[u] = timer++;
    vis[u] = 1;
    for (auto [v, i] : adj[u]) {
      if (v == p) continue;
      if (vis[v]) {
        low[u] = min(low[u], tin[v]);
        continue;
      }

      dfs(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] > tin[u]) result[i] = 1;
    }
  };
  for (int u = 0; u < n; u++) {
    if (vis[u]) continue;
    dfs(u, -1);
  }
  return result;
}

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int n; 
  int iter = 0;
  while(cin >> n) {
    if (iter++ != 0) cout << "\n";
    vector<Edge> edges;
    for (int i = 0; i < n; i++) {
      int x; cin >> x;
      string s; cin >> s;
      int m = stoi(s.substr(1, (int)s.size()-2));
      for (int j = 0; j < m; j++) {
        int y; cin >> y;
        if (x < y) edges.emplace_back(x, y);
      }
    }
    auto is_bridge = find_bridges(edges, n);

    vector<Edge> ans;
    for (int i = 0; i < edges.size(); i++) {
      if (!is_bridge[i]) continue;
      ans.push_back(edges[i]);
    }
    sort(ans.begin(), ans.end(), [](const Edge &left, const Edge &right) {
      return make_pair(left.u, left.v) < make_pair(right.u, right.v);
    });
    cout << ans.size() << " critical links\n";
    for (Edge &e : ans) {
      cout << e << "\n";
    }
  }
  cout << "\n";
}