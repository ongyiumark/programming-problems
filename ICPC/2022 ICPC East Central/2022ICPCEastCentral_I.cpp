#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

struct Edge {
  int u, v;
  ll w;
  Edge (int u, int v, ll w) : u(u), v(v), w(w) {}
  Edge reverse() const { return Edge(v, u, w); }
};

struct Graph {
  vector<Edge> edges;
  vector<vector<int>> adj;
  Graph(int n) : adj(n) {}
  vector<int>& operator[](const int u) { return adj[u]; }
  Edge& operator()(const int e) { return edges[e]; };
  void append(int u, const Edge &e) {
    adj[u].push_back(edges.size());
    edges.push_back(e);
  }
  void add_edge(const Edge& e) {
    append(e.u, e);
    append(e.v, e.reverse());
  };
  int size() { return adj.size(); }
};

const ll INF = 1e18;
vector<ll> dijkstra(Graph &g, int s) {
  vector<ll> d(g.size(), INF);
  priority_queue<pair<ll,int>> pq;
  d[s] = 0;
  pq.push({-d[s], s});

  while (!pq.empty()) {
    auto [cw, u] = pq.top();
    cw *= -1;
    pq.pop();

    if (d[u] < cw) continue;
    for (int e : g[u]) {
      if (d[g(e).v] > d[g(e).u] + g(e).w) {
        d[g(e).v] = d[g(e).u] + g(e).w;
        pq.push({-d[g(e).v], g(e).v});
      }
    } 
  }
  return d;
}

vector<bool> mark_edges(Graph &g, int s, int t) {
  vector<ll> d = dijkstra(g, s);
  vector<bool> edges(g.edges.size()/2);

  vector<bool> vis(g.size());
  function<void(int)> dfs = [&](int u) {
    vis[u] = 1;
    for (int e : g[u]) {
      if (d[g(e).v] != d[g(e).u]-g(e).w) continue;
      edges[e/2] = 1;
      if (vis[g(e).v]) continue;
      dfs(g(e).v);
    }
  };
  dfs(t);
  return edges;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, a, b; cin >> n >> m >> a >> b;
  a--; b--;
  Graph g(n);
  for (int i = 0; i < m; i++) {
    int u, v, w; cin >> u >> v >> w;
    u--; v--;
    g.add_edge(Edge(u, v, w));
  }

  vector<bool> edges = mark_edges(g, a, b);
  int total = 0;
  for (int i = 0; i < m; i++) {
    if (edges[i]) continue;
    total += g(2*i).w;
  }
  cout << total << "\n";

  return 0;
}