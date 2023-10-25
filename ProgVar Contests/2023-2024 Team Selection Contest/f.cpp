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

int di[] = {0,0,1,-1};
int dj[] = {1,-1,0,0};
const int N = 20;
const int T = 201;
int to_idx(int ct, int ci, int cj) {
  return ct*N*N + ci*N + cj;
}

struct Edge {
  int u, v;
  int c, f;
  Edge(int u, int v, int c, int f) : u(u), v(v), c(c), f(f) {}
  int resid() const { return c-f; }
  Edge reverse() const { return {v, u, 0, 0}; }
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
  void add_edge(const Edge &e) {
    append(e.u, e);
    append(e.v, e.reverse());
  }
};

const int INF = numeric_limits<int>::max();
int max_flow(Graph &g, int s, int t) {
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
    while (int b = augment(s, INF)) flow += b;
  }
  return flow;
}

vector<vector<char>> grid;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, t;
  cin >> n >> m >> t;
  grid.assign(n, vector(m, '.'));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> grid[i][j];

  vector<pair<int,int>> participants, exits;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 'P') participants.push_back({i, j});
      if (grid[i][j] == 'E') exits.push_back({i, j});
    }
  }
  Graph g(N*N*T + 5);

  for (int ct = 0; ct < t; ct++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == '#') continue;
        int u = to_idx(ct, i, j);
        for (int k = 0; k < 4; k++) {
          int x = i + di[k];
          int y = j + dj[k];
          if (x < 0 || x >= n || y < 0 || y >= m) continue;
          if (grid[x][y] == '#') continue;
          int v = to_idx(ct+1, x, y);
          g.add_edge(Edge(u, v, 1, 0));
        }
        int v = to_idx(ct+1, i, j);
        g.add_edge(Edge(u, v, 1, 0));
      }
    }
  }

  // attach source and sink
  int source, sink;
  source = g.size()-1;
  sink = g.size()-2;
  for (auto [i, j] : participants) {
    int v = to_idx(0, i, j);
    g.add_edge(Edge(source, v, 1, 0));
  }
  for (int ct = 0; ct <= t; ct++) {
    for (auto [i, j] : exits) {
      int v = to_idx(ct, i, j);
      g.add_edge(Edge(v, sink, 1, 0));
    }
  }
  cout << max_flow(g, source, sink) << "\n";

  return 0;
}
