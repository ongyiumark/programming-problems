#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int N = 1e5+5;
const int LG = 21;

struct edge {
  int u, v, c;
  ll d;
  edge reverse() const { return {v, u, c, d}; }
};

struct graph {
  vector<edge> edges;
  vector<vector<int>> adj;
  graph(int n) : adj(n) {}
  edge& operator()(int i) { return edges[i]; }
  vector<int>& operator[](int u) { return adj[u]; }
  int size() { return adj.size(); }
  void add_edge(const edge &e) {
    adj[e.u].push_back(edges.size());
    edges.push_back(e);

    adj[e.v].push_back(edges.size());
    edges.push_back(e.reverse());
  }
};

struct flat_tree {
  vector<vector<int>> par;
  vector<int> dep;
  vector<int> entry, exit;
  int counter = 0;
  
  flat_tree(graph &g) {
    par.resize(LG);
    int n = g.size();
    for (int k = 0; k < LG; k++) par[k].resize(n);
    dep.resize(n);
    entry.resize(n);
    exit.resize(n);

    par[0][0] = 0;
    dep[0] = 0;
    entry[0] = exit[0] = 0;
    dfs(g);

    for (int k = 1; k < LG; k++) {
      for (int u = 0; u < n; u++) {
        par[k][u] = par[k-1][par[k-1][u]];
      }
    }
  }

  void dfs(graph &g) {
    vector<bool> vis(g.size());
    function<void(int)> dfs = [&](int u) {
      vis[u] = true;
      entry[u] = counter++;
      for (int i : g[u]) {
        edge& e = g(i);
        if (vis[e.v]) continue;
        par[0][e.v] = e.u;
        dep[e.v] = dep[e.u]+1;
        dfs(e.v);
      }
      exit[u] = counter++;
    };
    dfs(0);
  }

  int lca(int a, int b) {
    if (dep[a] > dep[b]) swap(a, b);
    for (int k = LG-1; k >= 0; k--) {
      if (dep[par[k][b]] >= dep[a]) b = par[k][b];
    }
    if (a == b) return a;

    for (int k = LG-1; k >= 0; k--) {
      if (par[k][a] != par[k][b]) {
        a = par[k][a];
        b = par[k][b];
      }
    }
    return par[0][a];
  }
};


int main() {
  cin.tie(0)->sync_with_stdio(false);

  int n, q;
  cin >> n >> q;
  graph g(n);
  for (int i = 0; i < n-1; i++) {
    int a, b, c; ll d;
    cin >> a >> b >> c >> d;
    a--; b--; c--;
    g.add_edge({a, b, c, d});
  }

  flat_tree ft(g);
  vector<pair<int,ll>> s;
  s.push_back({0,0});
  vector<vector<pair<int,ll>>> s_color(n, {{0,0}}), n_color(n, {{0,0}});
  for (edge &e : g.edges) {
    if (e.u != ft.par[0][e.v]) continue;
    s.push_back({ft.entry[e.v], e.d});
    s.push_back({ft.exit[e.v], -e.d});

    s_color[e.c].push_back({ft.entry[e.v], e.d});
    s_color[e.c].push_back({ft.exit[e.v], -e.d});
    n_color[e.c].push_back({ft.entry[e.v], 1});
    n_color[e.c].push_back({ft.exit[e.v], -1});
  }
  for (int i = 0; i < n-1; i++) {
    sort(s_color[i].begin(), s_color[i].end());
    sort(n_color[i].begin(), n_color[i].end());
    int sz = s_color[i].size();
    for (int j = 1; j < sz; j++) {
      s_color[i][j].second += s_color[i][j-1].second;
      n_color[i][j].second += n_color[i][j-1].second;
    }
  }
  sort(s.begin(), s.end());
  for (int j = 1; j < s.size(); j++) {
    s[j].second += s[j-1].second;
  }

  auto query = [&](int u, int x, ll y) {
    int target = ft.entry[u];
    int index = -1;
    int lo = 0;
    int hi = (int)s_color[x].size()-1;
    while (lo <= hi) {
      int mid = hi-(hi-lo)/2;
      if (s_color[x][mid].first <= target) {
        index = mid;
        lo = mid+1;
      }
      else hi = mid-1;
    }
    return s[ft.entry[u]].second + n_color[x][index].second*y - s_color[x][index].second;
  };

  for (int i = 0; i < q; i++) {
    int x; ll y; int u, v;
    cin >> x >> y >> u >> v;
    x--; u--; v--;
    int anc = ft.lca(u, v);
    ll ans = query(u, x, y) + query(v, x, y) - 2*query(anc, x, y);
    cout << ans << "\n";
  }
  return 0;
}