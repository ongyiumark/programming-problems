#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

struct Edge {
  int u, v;
  Edge(int u, int v) : u(u), v(v) {}
  Edge reverse() const { return Edge(v, u); }
};

struct Graph {
  vector<vector<int>> adj;
  vector<Edge> edges;
  Graph(int n) : adj(n) {}
  int size() { return adj.size(); }
  vector<int>& operator[](const int u) { return adj[u]; }
  Edge& operator()(const int e) { return edges[e]; }
  void append(const Edge &e) {
    adj[e.u].push_back(edges.size());
    edges.push_back(e);
  }
  void add_edge(const Edge &e) {
    append(e);
  }
};

vector<int> kosaraju(Graph &g) {
  int n = g.size();
  Graph g_T(n);
  for (Edge &e : g.edges) g_T.add_edge(e.reverse());

  vector<bool> vis(n);
  vector<int> ts, p(n, -1);

  function<void(int,int)> dfs = [&](int u, int pass) {
    vis[u] = 1;
    Graph &cg = (pass == -1) ? g : g_T;
    if (pass > 0) p[u] = pass;
    for (int e : cg[u]) {
      if (vis[cg(e).v]) continue;
      dfs(cg(e).v, pass);
    }
    if (pass == -1) ts.push_back(u);
  };
  vis.assign(n, false);
  for (int u = 0; u < n; u++) 
    if (!vis[u]) dfs(u, -1);

  vis.assign(n, false);
  for (int i = n-1; i >= 0; i--) 
    if (!vis[ts[i]]) dfs(ts[i], ts[i]);
  
  return p;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<int> d(7), pd(8);
  for (int i = 0; i < 7; i++) cin >> d[i];
  for (int i = 1; i <= 7; i++) pd[i] += pd[i-1] + d[i-1];

  vector preds(n, vector<int>(7, 0));
  for (int i = 0; i < n; i++) {
    for(int j = 0; j < 7; j++) {
      cin >> preds[i][j];
    }
  }

  int b6, b7; cin >> b6 >> b7;
  auto get_num = [&](int day, int b) { return pd[day-1]+b-1; };
  auto possible = [&](int r6, int r7) {
    vector<int> results(pd[7], -1);
    results[get_num(6, abs(r6))] = (r6 > 0);
    results[get_num(7, abs(r7))] = (r7 > 0);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 7; j++) {
        int day = j+1;
        int r = -preds[i][j]; // assume wrong
        int id = get_num(day, abs(r));
        if (results[id] != -1 && results[id] != (r > 0)) return false;
        results[id] = (r > 0); 
      }
    }
    return true;
  };
  if (possible(b6, -b7) || possible(-b6, b7)) {
    cout << "possible\n";
    return 0;
  }

  // check assuming both b6 and b7 are correct
  // other participants and only get at most 1 correct
  Graph g(2*pd[7]+5);
  auto get_graph_id = [&](int day, int b) {
    return get_num(day, abs(b)) + pd[7]*(b < 0);
  };

  for (int i = 0; i < n; i++) {
    for (int j1 = 0; j1 < 7; j1++) {
      for (int j2 = 0; j2 < 7; j2++) {
        if (j1 == j2) continue;
        int day1 = j1+1, day2 = j2+1;
        int u = get_graph_id(day1, preds[i][j1]);
        int v = get_graph_id(day2, -preds[i][j2]);
        g.add_edge(Edge(u, v));
        //cout << u << " -> " << v << endl;
      }
    }
  }
  g.add_edge(Edge(get_graph_id(6, -b6), get_graph_id(6, b6)));
  g.add_edge(Edge(get_graph_id(7, -b7), get_graph_id(7, b7)));

  
  vector<int> scc = kosaraju(g);
  for (int i = 0; i < pd[7]; i++) {
    int a = scc[i];
    int b = scc[i+pd[7]];
    if (a == b) {
      cout << "impossible\n";
      return 0;
    }
  }
  cout << "possible\n";
  return 0;
}