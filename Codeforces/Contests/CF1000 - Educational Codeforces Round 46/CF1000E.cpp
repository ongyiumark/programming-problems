#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge {
  int u, v;
  ll w;
  Edge (int u, int v) : u(u), v(v), w(0) {}
  Edge (int u, int v, ll w) : u(u), v(v), w(w) {}
  Edge reverse() const { return Edge(v, u, w); }
};
struct Graph {
  vector<Edge> edges;
  vector<vector<int>> adj;
  Graph(int n) : adj(n) {}
  Edge& operator()(int e) { return edges[e]; }
  vector<int>& operator[](int u) { return adj[u]; }
  int size() { return adj.size(); }
  void append(const Edge& e) {
    adj[e.u].push_back(edges.size());
    edges.push_back(e);
  }
  void add_edge(const Edge& e, bool directed=false) {
    append(e);
    if (!directed) append(e.reverse());
  }
};

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

Graph build_bridge_tree(vector<Edge> &edges, int n) {
  auto is_bridge = find_bridges(edges, n);
  int m = is_bridge.size();
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    if (is_bridge[i]) continue;
    auto &e = edges[i];
    adj[e.u].emplace_back(e.v);
    adj[e.v].emplace_back(e.u);
  }

  vector<bool> vis(n); vector<int> root(n);
  function<void(int,int)> dfs = [&](int u, int x) {
    vis[u] = 1; root[u] = x;
    for (int &v : adj[u]) {
      if (vis[v]) continue;
      dfs(v, x);
    }
  };

  int tree_sz = 0;
  for (int i = 0; i < n; i++) 
    if (!vis[i]) dfs(i, tree_sz++);
  
  Graph tree(tree_sz);
  for (int i = 0; i < m; i++) {
    if (!is_bridge[i]) continue;
    int u = root[edges[i].u];
    int v = root[edges[i].v];
    tree.add_edge(Edge(u, v));
  }
  return tree;
}

const int INF = 1e9;
vector<int> bfs(vector<vector<int>>& adj, int s) {
  vector<int> dist(adj.size(), INF);
  dist[s] = 0;
  queue<int> q; q.push(s);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int &v : adj[u]) {
      if (dist[v] < INF) continue;
      dist[v] = dist[u]+1;
      q.push(v);
    }
  }
  return dist;
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int n, m; cin >> n >> m;
  
  vector<Edge> edges;

  for (int i = 0; i < m; i++) {
    int x, y; cin >> x >> y;
    x--; y--;
    edges.emplace_back(x, y);
  }
  Graph tree = build_bridge_tree(edges, n);
  
  int sz = tree.size();
  vector<vector<int>> adj(sz);
  for (auto &e : tree.edges) {
    adj[e.u].emplace_back(e.v);
    //cout << e.u << " " << e.v << endl;
  }

  auto d1 = bfs(adj, 0);
  int argmax = max_element(d1.begin(), d1.end())-d1.begin();
  auto d2 = bfs(adj, argmax);
  cout << *max_element(d2.begin(), d2.end()) << "\n";
  return 0;
}