#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e7;

vector<bool> isc(N);
void sieve() {
  isc[0] = 1, isc[1] = 1;
  for (int i = 2; i < N; i++) {
    if (isc[i]) continue;
    for (int j = i+i; j < N; j += i) isc[j] = 1;
  }
}

const int INF = numeric_limits<int>::max();

struct edge {
  int u, v;
  int c, f;
  int resid() const { return c-f; }
  edge reverse() const { return {v, u, 0, 0}; }
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

int max_flow(graph &g, int s, int t) {
  int n = g.size();
  vector<int> adj_ptr(n), d(n);

  auto make_level_graph = [&]() {
    fill(d.begin(), d.end(), INF);
    queue<int> q; q.push(s);
    d[s] = 0;

    while(!q.empty()) {
      int u = q.front();
      q.pop();
      
      for (int e : g[u]) {
        if (d[g(e).v] < INF || g(e).resid() <= 0) continue;
        d[g(e).v] = d[g(e).u]+1;
        q.push(g(e).v);
      }
    }

    return d[t] < INF;
  };

  function<int(int,int)> augment = [&](int u, int b) {
    if (u == t) return b;

    for (int &ii = adj_ptr[u]; ii < g[u].size(); ii++) {
      int e = g[u][ii];
      if (g(e).resid() <= 0 || d[g(e).v] != d[g(e).u]+1) continue;
      int bf = augment(g(e).v, min(b, g(e).resid()));
      if (!bf) continue;

      g(e).f += bf; g(e^1).f -= bf; 
      return bf;
    }

    return 0;
  };

  int flow = 0;
  while(make_level_graph()) {
    fill(adj_ptr.begin(), adj_ptr.end(), 0);
    while(int b = augment(s, INF)) flow += b;
  }
  return flow;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<int> p(n);
  for (int &x : p) cin >> x;

  int ones_cnt = count_if(p.begin(), p.end(), [](const int &x) { return x == 1; });
  int ones_idx = find(p.begin(), p.end(), 1)-p.begin();
  sieve();

  graph g(n+2);
  int source = n;
  int sink = n+1;

  for (int i = 0; i < n; i++) {
    if (ones_cnt && p[i]%2 == 0) g.add_edge({i, ones_idx, 1, 0});
    if (p[i]%2 == 0) g.add_edge({source, i, 1, 0});
    if (p[i]%2 == 1) g.add_edge({i, sink, 1, 0});


    for (int j = i+1; j < n; j++) {
      if (p[i] == 1 || p[j] == 1 || isc[p[i]+p[j]]) continue; 

      if (p[i]%2 == 0) g.add_edge({i, j, 1, 0});
      else g.add_edge({j, i, 1, 0});
    }
  }

  int flow = max_flow(g, source, sink);
  cout << n-flow-max(0, ones_cnt-1) << endl;
  return 0;
}