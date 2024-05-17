#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

struct Edge {
  int u, v;
  ll w;
  Edge(int u, int v, ll w) : u(u), v(v), w(w) {}
  Edge reverse() const { return Edge(v, u, w); }
};

struct Graph {
  vector<vector<int>> adj;
  vector<Edge> edges;
  
  Graph(int n) : adj(n) {}
  int size() { return adj.size(); }
  vector<int>& operator[](const int &u) { return adj[u]; }
  Edge& operator()(const int &e) { return edges[e]; }
  void append(const Edge &e) {
    adj[e.u].push_back(edges.size());
    edges.push_back(e);
  }
  void add_edge(const Edge &e) {
    append(e);
  }
};

const ll INF = 1e18;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m; cin >> n >> m;
  vector<ll> cost(n+1);
  vector price(n, vector<ll>());
  for (int i = 0; i < n; i++) {
    cin >> cost[i];
    for (int j = 0; j < min(m, n-i); j++) {
      ll p; cin >> p;
      price[i].push_back(p);
    }
  }

  Graph g(n+1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < price[i].size(); j++) {
      g.add_edge(Edge(i, i+j+1, cost[i+j+1]-price[i][j]));
    }
  }
  vector<ll> memo(n+1, -1);
  vector<bool> seen(n+1, 0);
  function<ll(int)> solve = [&](int u) {
    if (seen[u]) return memo[u];
    seen[u] = 1;
    ll &ans = memo[u];
    if (u == n) return ans = 0;

    ans = INF;
    for (int e : g[u]) {
      ans = min(ans, g(e).w + solve(g(e).v));
    }
    return ans;
  };
  cout << cost[0]+solve(0) << "\n";


  return 0;
}