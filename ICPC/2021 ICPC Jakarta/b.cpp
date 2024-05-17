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
    int u = edges[i].u, v = edges[i].v;
    ll w = edges[i].w;
    if (!uf.unite(u, v)) continue;
    in_mst[i] = 1;
    num_taken++;
    if (num_taken == n-1) break;
  }
  return in_mst;
}


const ll INF = 1e18;
struct MinSegmentTree {
  vector<ll> st, lazy;
  int n;
  MinSegmentTree() {}
  MinSegmentTree(int n) : n(n) {
    st.assign(4*n, INF);
    lazy.assign(4*n, INF);
  }

  void pull(int p) {
    st[p] = min(st[p<<1], st[p<<1|1]);
  }

  void push(int p, int i, int j) {
    if (lazy[p] < INF) {
      st[p] = min(st[p], lazy[p]);
      if (i != j) {
        lazy[p<<1] = min(lazy[p], lazy[p<<1]);
        lazy[p<<1|1] = min(lazy[p], lazy[p<<1|1]);
      }
      lazy[p] = INF;
    }
  } 

  void update(int l, int r, ll v) { update (l, r, v, 1, 0, n-1); }
  void update(int l, int r, ll v, int p, int i, int j) {
    push(p, i, j);
    if (l <= i && j <= r) {
      lazy[p] = min(lazy[p], v);
      push(p, i, j);
    }
    else if (j < l || i > r);
    else {
      int k = (i+j)/2;
      update(l, r, v, p<<1, i, k);
      update(l, r, v, p<<1|1, k+1, j);
      pull(p);
    }
  }

  ll query(int l, int r) { return query(l, r, 1, 0, n-1); }
  ll query(int l, int r, int p, int i, int j) {
    push(p, i, j);
    if (l <= i && j <= r) return st[p];
    else if (j < l || i > r) return INF;
    else {
      int k = (i+j)/2;
      return min(query(l, r, p<<1, i, k), 
        query(l, r, p<<1|1, k+1, j));
    }
  }
};

struct SparseTable {
  vector<ll> lg;
  vector<vector<ll>> spt;
  int lgsz;
  SparseTable() {}
  SparseTable(vector<ll> &ar) {
    int n = ar.size();
    lgsz = 1; for (int i = 1; i < n; i <<= 1, lgsz++);
    lg.assign(n+1, 0); spt.assign(lgsz, vector<ll>(n, 0LL));

    lg[0] = lg[1] = 0;
    for (int i = 2; i <= n; i++) lg[i] = lg[i>>1] + 1;
    for (int i = 0; i < n; i++) spt[0][i] = ar[i];
    for (int j = 0; (2 << j) <= n; j++)
      for (int i = 0; i + (2 << j) <= n; i++)
        spt[j+1][i] = max(spt[j][i], spt[j][i+(1<<j)]);
  } 
  ll query(int a, int b) {
    int k = lg[b-a+1], ab = b - (1<<k) + 1;
    return max(spt[k][a], spt[k][ab]);
  }
};

struct HeavyLightTree {
  int n; 
  Graph g;
  vector<int> par, heavy, dep, path_root, pos;
  MinSegmentTree st;
  SparseTable st_max;
  vector<ll> sparse_arr;

  HeavyLightTree(Graph &g) : g(g), st(g.size()) {
    n = g.size();
    par.assign(n, -1); dep.assign(n, 0);
    path_root.assign(n, 0); pos.assign(n, 0);
    sparse_arr.assign(n, -INF);

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

  ll query(int u) { 
    return st.query(pos[u], pos[u]);
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


  ll query_edge(int u, int v) {
    ll res = -INF;
    while (path_root[u] != path_root[v]) {
      if (dep[path_root[u]] > dep[path_root[v]]) swap(u, v);
      res = max(res, st_max.query(pos[path_root[v]], pos[v]));
      v = par[path_root[v]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    if (u != v)
      res = max(res, st_max.query(pos[u]+1, pos[v]));
    return res;
  }

  void update_edge(int u, ll c) {
    sparse_arr[pos[u]] = c;
  }

  void build_sparse() {
    st_max = SparseTable(sparse_arr);
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

  HeavyLightTree hlt(g);

  function<void(int,int)> dfs = [&](int u, int p) {
    for (int &e : g[u]) {
      int v = g(e).v;
      if (v == p) continue;
      hlt.update_edge(v, g(e).w);
      dfs(v, u);
    }
  };
  dfs(0, -1);
  hlt.build_sparse();

  for (int i = 0; i < m; i++) {
    if (in_mst[i]) continue;
    int u = edges[i].u, v = edges[i].v;
    ll w = edges[i].w;
    hlt.update(u, v, max(w, hlt.query_edge(u, v)));
  }

  for (int i = 0; i < n; i++) {
    ll ans = hlt.query(i);
    cout << (ans == INF ? -1 : ans) << " \n"[i+1==n];
  }

  return 0;
}