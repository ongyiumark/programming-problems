#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge {
  int u, v;
  ll w;
  Edge(int u, int v) : u(u), v(v), w(0) {}
  Edge reverse() const { return Edge(v, u); } 
};

struct Graph {
  vector<Edge> edges;
  vector<vector<int>> adj;
  Graph(int n) : adj(n) {}
  int size() { return adj.size(); }
  vector<int>& operator[](const int u) { return adj[u]; }
  Edge& operator()(const int e) { return edges[e]; }
  void append(const Edge& e) {
    adj[e.u].push_back(edges.size());
    edges.push_back(e);
  }
  void add_edge(const Edge &e, bool directed=false) {
    append(e);
    if (!directed) append(e.reverse());
  }
};

struct SegmentTree {
  int n;
  vector<int> st, lazy;
  SegmentTree(int n) : n(n), st(4*n), lazy(4*n) {}
  SegmentTree(const vector<int> &ar) {
    n = ar.size();
    st.assign(4*n, 0); lazy.assign(4*n, 0);
    build(ar, 1, 0, n-1);
  }

  void build(const vector<int>& ar, int p, int i, int j) {
    if (i == j) {
      st[p] = ar[i];
      return;
    }
    int k = (i+j)/2;
    build(ar, p<<1, i, k);
    build(ar, p<<1|1, k+1, j);
    pull(p);
  }

  void pull(int p) { st[p] = st[p<<1] + st[p<<1|1]; }
  void push(int p, int i, int j) {
    if (lazy[p]) {
      st[p] += (j-i+1)*lazy[p];
      if (i != j) {
        lazy[p<<1] += lazy[p];
        lazy[p<<1|1] += lazy[p];
      }
      lazy[p] = 0;
    }
  }

  void update(int l, int r, int v) { 
    update(l, r, v, 1, 0, n-1); 
  }
  void update(int l, int r, int v, int p, int i, int j) {
    push(p, i, j);
    if (l <= i && j <= r) {
      lazy[p] += v;
      push(p, i, j);
    }
    else if (j < l || r < i) {}
    else {
      int k = (i+j)/2;
      update(l, r, v, p<<1, i, k);
      update(l, r, v, p<<1|1, k+1, j);
      pull(p);
    }
  }

  int query(int l, int r) { return query(l, r, 1, 0, n-1); }
  int query(int l, int r, int p, int i, int j) {
    push(p, i, j);
    if (l <= i && j <= r) { return st[p]; }
    else if (j < l || r < i) { return 0; }
    else {
      int k = (i+j)/2;
      return query(l, r, p<<1, i, k) 
        + query(l, r, p<<1|1, k+1, j);
    }
  }
};

struct HeavyLightTree {
  int n; 
  Graph g;
  vector<int> par, heavy, dep, path_root, pos;
  SegmentTree st;

  HeavyLightTree(Graph &g) : g(g), st(g.size()) {
    n = g.size();
    par.assign(n, -1); dep.assign(n, 0);
    path_root.assign(n, 0); pos.assign(n, 0);

    heavy.assign(n, -1);
    par[0] = 0; dep[0] = 0;
    function<int(int)> dfs = [&](int u) {
      int sz = 1;
      int max_subtree_sz = 0;
      for (int &e : g[u]) {
        int v = g(e).v;
        if (v == par[u]) continue;
        par[v] = u;
        dep[v] = dep[u]+1;
        int subtree_sz = dfs(v);
        if (max_subtree_sz < subtree_sz) {
          max_subtree_sz = subtree_sz;
          heavy[u] = v;
        }
        sz += subtree_sz;
      }
      return sz;
    };
    dfs(0);
    int p = 0;
    for (int u = 0; u < n; u++) 
      if (par[u] == -1 || heavy[par[u]] != u) 
        decompose(u, p);
  }

  void decompose(int u, int &p) {
    for (int v = u; v != -1; v = heavy[v])
      path_root[v] = u, pos[v] = p++;
  }

  ll query(int u, int v) {
    ll res = 0;
    while (path_root[u] != path_root[v]) {
      if (dep[path_root[u]] > dep[path_root[v]]) swap(u, v);
      res += st.query(pos[path_root[v]], pos[v]);
      v = par[path_root[v]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    res += st.query(pos[u], pos[v]);
    return res;
  }

  void update(int u, int v, ll c) {
    while (path_root[u] != path_root[v]) {
      if (dep[path_root[u]] > dep[path_root[v]]) swap(u, v);
      st.update(pos[path_root[v]], pos[v], c);
      v = par[path_root[v]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    st.update(pos[u], pos[v], c);
  }
};

void testcase(int number) {
  int n; cin >> n;
  Graph g(n);
  for (int i = 0; i < n-1; i++) {
    int u, v; cin >> u >> v;
    g.add_edge(Edge(u, v));
  }
  HeavyLightTree hlt(g);
  int q; cin >> q;
  while (q--) {
    int a, b, c; cin >> a >> b >> c;
    hlt.update(a, b, c);
  }

  cout << "Case #" << number << ":\n";
  for (int i = 0; i < n; i++) {
    cout << hlt.query(i, i) << "\n";
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;
  for (int tt = 1; tt <= t; tt++) testcase(tt);

  return 0;
}