#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ll,int> ii;
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

pair<ll, ll> min_cost_flow(graph &g, int s, int t) {
  vector<bool> vis(g.size());
  vector<int> p(g.size());
  vector<ll> d(g.size()), pot(g.size());

  auto augment = [&]() {
    fill(vis.begin(), vis.end(), false);
    fill(d.begin(), d.end(), numeric_limits<ll>::max());

    priority_queue<pair<ll, int>> pq; pq.push({d[s] = 0, s});
    while (!pq.empty()) {
      int u = pq.top().second;
      pq.pop();
      if (vis[u]) continue;

      vis[u] = true;
      for (int e : g[u]) {
        ll w = d[g(e).u] + g(e).w + pot[g(e).u] - pot[g(e).v];
        if (vis[g(e).v] || g(e).resid() <= 0 || d[g(e).v] <= w) continue;
        d[g(e).v] = w;
        p[g(e).v] = e;
        pq.push({-w, g(e).v});
      }
    }

    return d[t] < numeric_limits<ll>::max();
  };

  ll flow = 0, cost = 0;
  while (augment()) {
    ll b = numeric_limits<ll>::max();
    for (int v = t; v != s; v = g(p[v]).u) b = min(b, g(p[v]).resid());
    for (int v = t; v != s; v = g(p[v]).u) {
      g(p[v]).f += b; g(p[v]^1).f -= b;
      cost += b * g(p[v]).w;
    }
    flow += b;
    for (int u = 1; u < g.size(); u++) {
      pot[u] += d[u];
    }
  }

  return {flow, cost};
} 


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  vector<vector<ll>> L(n+2, vector<ll>(n+2, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> L[i][j];
    }
  }

  graph g(n+4);
  int s = n+2;
  int t = n+3;

  for (int i = 1; i <= n; i += 2) {
    g.add_edge({s, i, 0, 1});
    for (int j = 2; j <= n+1; j += 2) {
      g.add_edge({i, j, L[j-2][i]+L[i][j], 1});
    }
  }
  for (int j = 2; j <= n+1; j += 2) {
    g.add_edge({j, t, 0, 1});
  }

  auto [flow, cost] = min_cost_flow(g, s, t);
  cout << cost << "\n";
  
  return 0;
}
