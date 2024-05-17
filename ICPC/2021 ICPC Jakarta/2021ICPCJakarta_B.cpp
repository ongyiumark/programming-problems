#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Edge {
  int u, v;
  ll w;
  Edge (int u, int v, ll w) : u(u), v(v), w(w) {}
  Edge reverse() const { return Edge(v, u, w); }
};

struct Graph {
  vector<vector<int>> adj;
  vector<Edge> edges;
  Graph(int n) : adj(n) {}
  int size() { return adj.size(); }
  vector<int>& operator[](int u) { return adj[u]; }
  Edge& operator()(int e) { return edges[e]; }
  void append(const Edge& e) {
    adj[e.u].push_back(edges.size());
    edges.push_back(e);
  }
  void add_edge(const Edge &e, bool directed=false) {
    append(e);
    if (!directed) append(e.reverse());
  }
};

struct UnionFind {
  vector<int> p;
  UnionFind(int n) : p(n, -1) {}
  int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
  }
  bool unite(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return false;
    if (p[a] > p[b]) swap(a, b);
    p[a] += p[b]; p[b] = a;
    return true;
  }
  bool is_same(int a, int b) { return find(a) == find(b); }
  int size(int a) { return -p[find(a)]; }
};

vector<bool> kruskals(vector<Edge>& edges, int n) {
  UnionFind uf(n);
  sort(edges.begin(), edges.end(), [](const Edge& left, const Edge& right) {
    return left.w < right.w;
  });

  int m = edges.size();
  vector<bool> in_mst(m);
  int num_taken = 0;
  for (int i = 0; i < m; i++) {
    auto &[u, v, w] = edges[i];
    if (!uf.unite(u, v)) continue;
    in_mst[i] = 1;
    num_taken++;
    if (num_taken == n-1) break;
  }
  return in_mst;
}

struct LCA {
  vector<vector<int>> par;
  vector<int> depth;
  int sz, n;
  LCA(Graph &tree) {
    n = tree.size();
    sz = 2;
    for (int i = 1; i < n; i *= 2, sz++);

    par.assign(sz, vector(n, -1));
    depth.assign(n, 0);

    function<void(int, int)> dfs = [&](int u, int p) {
      for (int e : tree[u]) {
        int v = tree(e).v;
        if (v == p) continue;
        par[0][v] = u;
        depth[v] = depth[u]+1;
        dfs(v, u);
      }
    };
    par[0][0] = 0;
    dfs(0, -1);

    for (int i = 1; i < sz; i++) {
      for (int j = 0; j < n; j++) {
        par[i][j] = par[i-1][par[i-1][j]];
      }
    }
  }

  int get_ancestor(int a, int b) {
    if (depth[a] > depth[b]) swap(a, b);
    for (int i = sz-1; i >= 0; i--) {
      if (depth[par[i][b]] < depth[a]) continue;
      b = par[i][b];
    }

    if (a == b) return a;
    for (int i = sz-1; i >= 0; i--) {
      if (par[i][a] == par[i][b]) continue;
      a = par[i][a]; b = par[i][b];
    }
    return par[0][a];
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m; cin >> n >> m;
  vector<ll> h(n);
  for (ll &x : h) cin >> x;

  vector<Edge> edges;
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    u--; v--;
    edges.push_back(Edge(u, v, abs(h[u]-h[v])));
  }

  auto in_mst = kruskals(edges, n);
  Graph g(n);
  for (int i = 0; i < m; i++) {
    if (!in_mst[i]) continue;
    g.add_edge(edges[i]);
  }

  LCA lca(g);
  auto &depth = lca.depth;
  auto &par = lca.par;

  vector<int> skip(n+1);
  for (int i = 0; i <= n; i++) skip[i] = i;
  function<int(int)> skip_to = [&](int x) {
    if (skip[x] == x) return x;
    return skip[x] = skip_to(skip[x]);
  };

  vector<ll> ans(n,-1);
  vector<int> parent(n);
  for (int i = 0; i < n; i++) parent[i] = par[0][i];
  parent[0] = n;
  for (int i = 0; i < m; i++) {
    if (in_mst[i]) continue;
    auto [u, v, w] = edges[i];
    
    int ancestor = lca.get_ancestor(u, v);
    u = skip_to(u);
    while (u < n && depth[u] >= depth[ancestor]) {
      ans[u] = w;
      skip[u] = parent[u];
      u = skip_to(u);
    }
    v = skip_to(v);
    while (v < n && depth[v] >= depth[ancestor]) {
      ans[v] = w;
      skip[v] = parent[v];
      v = skip_to(v);
    }
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << (" \n"[i+1==n]);
  }

  return 0;
}