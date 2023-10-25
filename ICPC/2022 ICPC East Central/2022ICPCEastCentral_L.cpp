#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

struct Edge {
  int u, v;
  ll w, c, f;
  Edge (int u, int v, ll c, ll f) : 
    u(u), v(v), w(0), c(c), f(f) {}
  Edge (int u, int v, ll w, ll c, ll f) : 
    u(u), v(v), w(w), c(c), f(f) {}
  ll resid() const { return c-f; }
  Edge reverse() const { return Edge(v, u, -w, 0, 0); }
};

struct Graph {
  vector<Edge> edges;
  vector<vector<int>> adj;
  Graph(int n) : adj(n) {}
  Edge& operator()(int e) { return edges[e]; }
  vector<int>& operator[](int u) { return adj[u]; }
  int size() { return adj.size(); }
  void append(int u, const Edge& e) {
    adj[u].push_back(edges.size());
    edges.push_back(e);
  }
  void add_edge(const Edge& e) {
    append(e.u, e);
    append(e.v, e.reverse());
  }
};

const ll INF = 1e18;
pair<ll,ll> min_cost_flow(Graph &g, int s, int t) {
  int n = g.size();
  vector<bool> vis(n);
  vector<int> p(n);
  vector<ll> d(n), pot(n);

  auto augment = [&]() {
    fill(vis.begin(), vis.end(), false);
    fill(d.begin(), d.end(), INF);
    priority_queue<pair<ll, int>> pq;
    pq.push({d[s] = 0, s});
    while(!pq.empty()) {
        int u = pq.top().second; pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for(int e : g[u]) {
          ll w = d[g(e).u] + pot[g(e).u] + g(e).w - pot[g(e).v];
          if (vis[g(e).v] || g(e).resid() <= 0 || d[g(e).v] <= w) continue;
          d[g(e).v] = w;
          p[g(e).v] = e;
          pq.push({-d[g(e).v], g(e).v});
        }
    }
    return d[t] < INF;
  };
  if(count_if(g.edges.begin(), g.edges.end(), [](const Edge& e) { return e.c and e.w < 0; })) {
    fill(pot.begin(), pot.end(), INF);
    pot[s] = 0;
    for(int i = 0; i < g.size() - 1; i++) {
      for(const Edge& e : g.edges) {
        if(e.c and pot[e.u] < INF) {
          pot[e.v] = min(pot[e.v], pot[e.u] + e.w);
        }
      }
    }
  }
  ll flow = 0, cost = 0;
  while(augment()) {
    ll b = INF;
    for(int v = t; v != s; v = g(p[v]).u) {
      b = min(b, g(p[v]).resid());
    }
    for(int v = t; v != s; v = g(p[v]).u) {
      g(p[v]).f += b, g(p[v] ^ 1).f -= b;
      cost += b * g(p[v]).w;
    }
    flow += b;
    for(int u = 0; u < g.adj.size(); u++) {
      pot[u] += d[u];
    }
  }
  return {flow, cost};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m; cin >> n >> m;
  vector num_products(n, vector<ll>(m, 0));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> num_products[i][j];
  
  vector distances(n, vector<ll>(n, 0));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> distances[i][j];
  
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (distances[i][j] == -1)
        distances[i][j] = INF;
  
  // floyd warshall
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        distances[i][j] = min(distances[i][j], distances[i][k]+distances[k][j]);
  
  Graph g(n+n+2);
  int source = n+n;
  int sink = n+n+1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      // assign warehouse i to product j
      if (j >= m) {
        g.add_edge(Edge(j, i+n, 0, 1, 0));
        continue;
      }
      ll total = 0;
      for (int k = 0; k < n; k++) {
        total += num_products[k][j]*distances[k][i];
      }
      g.add_edge(Edge(j, i+n, total, 1, 0));
    }
  }
  // add source and sink
  for (int i = 0; i < n; i++) g.add_edge(Edge(i+n, sink, 0, 1, 0));
  for (int j = 0; j < n; j++) g.add_edge(Edge(source, j, 0, 1, 0));

  auto [flow, cost] = min_cost_flow(g, source, sink);

  cout << cost << "\n";
  return 0;
}