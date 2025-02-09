#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct edge {
  int u, v; ll w, c, f;
  ll resid() { return c-f; }
  edge reverse() const { return {v, u, -w, 0, 0}; }
};

struct graph {
  vector<edge> edges;
  vector<vector<int>> adj;
  graph(int n) : adj(n) {}
  edge& operator()(int e) { return edges[e]; }
  vector<int>& operator[](int u) { return adj[u]; }
  int size() { return adj.size(); }
  void append(int u, const edge& e) {
    adj[u].push_back(edges.size());
    edges.push_back(e);
  }
  void add_edge(const edge& e) {
    append(e.u, e);
    append(e.v, e.reverse());
  }
};

ll max_flow(graph &g, int s, int t) {
  vector<bool> vis(g.size());
  vector<int> p(g.size()), adj_ptr(g.size());
  vector<ll> d(g.size());

  auto make_level_graph = [&]() {
    fill(d.begin(), d.end(), numeric_limits<ll>::max());
    queue<int> q; q.push(s);
    d[s] = 0;

    while (!q.empty()) {
      int u = q.front();
      q.pop();

      for (int e : g[u]) {
        if (d[g(e).v] < numeric_limits<ll>::max() || g(e).resid() <= 0) continue;
        p[g(e).v] = e;
        d[g(e).v] = d[g(e).u]+1;
        q.push(g(e).v);
      }
    }
    return d[t] < numeric_limits<ll>::max();
  };

  auto augment = [&]() {
    fill(vis.begin(), vis.end(), false);
    queue<int> q; q.push(s);

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      if (vis[u]) continue;
      vis[u] = true;
      for (int &ii = adj_ptr[u]; ii < g[u].size(); ii++) {
        int e = g[u][ii];
        if (vis[g(e).v] || g(e).resid() <= 0 || d[g(e).v] != d[g(e).u]+1) continue;
        p[g(e).v] = e;
        q.push(g(e).v);
      }
    }

    return vis[t];
  };

  ll flow = 0;
  while (make_level_graph()) {
    fill(adj_ptr.begin(), adj_ptr.end(), 0);

    while(augment()) {
      ll b = numeric_limits<ll>::max();
      for (int v = t; v != s; v = g(p[v]).u) b = min(b, g(p[v]).resid());
      for (int v = t; v != s; v = g(p[v]).u) {
        g(p[v]).f += b; 
        g(p[v]^1).f -= b;
      }
      flow += b;
    }
  }

  return flow;
} 

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int h, w, n; cin >> h >> w >> n;
  // 0-99 - reserve for rows
  // 100-199 - reserve for cols
  // 200-299 - reserve for pieces with possible rows
  // 300-399 - reserve for piece with possible cols
  // 400 - source
  // 401 - sink

  int source = 400;
  int sink = 401;

  graph g(402);
  for (int i = 0; i < 100; i++) g.add_edge({source, i, 1, 1, 0});   // source to rows
  for (int i = 0; i < 100; i++) g.add_edge({i+100, sink, 1, 1, 0});  // cols to sink

  for (int i = 0; i < n; i++) {
    int a, b, c, d; cin >> a >> b >> c >> d;
    a--; b--; c--; d--;
    for (int row = a; row <= c; row++) g.add_edge({row, i+200, 1, 1, 0}); // possible rows
    for (int col = b; col <= d; col++) g.add_edge({i+300, col+100, 1, 1, 0}); // possible cols
    g.add_edge({i+200, i+300, 1, 1, 0}); // connect possible rows to cols
  }

  ll flow = max_flow(g, source, sink);
  cout << flow << endl;

  return 0;
}
