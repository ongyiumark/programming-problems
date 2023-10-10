#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int LGN = 20;

void dfs(int u, vector<vector<int>> &adj, vector<int> &d, vector<int> &st, vector<vector<int>> &par) {
  st[u] = 1;
  for (int &v : adj[u]) {
    if (v == par[0][u]) continue;
    d[v] = d[u]+1;
    par[0][v] = u;

    dfs(v, adj, d, st, par);
    st[u] += st[v];
  }
}

int lca(int u, int v, vector<int> &d, vector<vector<int>> &par) {
  if (d[u] < d[v]) swap(u, v);

  for (int k = LGN-1; k >= 0; k--) {
    if (d[par[k][u]] < d[v]) continue;
    u = par[k][u];
  }

  assert(d[u] == d[v]);
  if (u == v) return u;
  for (int k = LGN-1; k >= 0; k--) {
    if (par[k][u] == par[k][v]) continue;
    u = par[k][u];
    v = par[k][v];
  }

  return par[0][u];
}

int dist(int u, int v, vector<int> &d, vector<vector<int>> &par) {
  return d[u] + d[v] - 2*d[lca(u, v, d, par)];
}

int ancestor(int u, int x, vector<vector<int>> &par) {
  for (int k = 0; k < LGN; k++) {
    if (x & (1 << k)) u = par[k][u];
  }
  return u;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ifstream f("library.in", ios::in);
  int t; f >> t;
  while (t--) {
    int n, q; f >> n >> q;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n-1; i++) {
      int u, v; f >> u >> v;
      u--; v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

  
    vector<vector<int>> par(LGN, vector<int>(n));
    vector<int> d(n), st(n);
    d[0] = 0;
    par[0][0] = 0;
    dfs(0, adj, d, st, par);
  
    for (int k = 1; k < LGN; k++) {
      for (int i = 0; i < n; i++) {
        par[k][i] = par[k-1][par[k-1][i]];
      }
    }
    
    while(q--) {
      int a, b; f >> a >> b;
      a--; b--;
      
      int distance = dist(a, b, d, par);
      if (d[a] > d[b]) swap(a, b);

      if (a == b) cout << n << "\n";
      else if (distance % 2 == 1) cout << 0 << "\n";
      else {
        int mida = ancestor(a, distance/2-1, par);
        int midb = ancestor(b, distance/2-1, par);
        
        if (par[0][mida] != par[0][midb]) cout << st[par[0][midb]] - st[midb] << "\n";
        else cout << st[0] - st[mida] - st[midb] << "\n";     
      }
    }
  }

  f.close();

  return 0;
}