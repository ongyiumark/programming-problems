#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int LGN = 17;
const int INF = 1e9;

void dfs(int u, vector<vector<int>> &adj, vector<int> &d, vector<vector<int>> &par) {
  for (int v : adj[u]) {
    if (v == par[0][u]) continue;
    d[v] = d[u]+1;
    par[0][v] = u;
    dfs(v, adj, d, par);
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    vector<vector<int>> par(LGN, vector<int>(n));
    for (int i = 0; i < n-1; i++) {
      int a, b; cin >> a >> b;
      a--; b--;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    vector<int> d(n, INF);
    d[0] = 0;
    par[0][0] = 0;
    dfs(0, adj, d, par);

    for (int k = 1; k < LGN; k++) {
      for (int i = 0; i < n; i++) {
        par[k][i] = par[k-1][par[k-1][i]];
      }
    }

    bool val = true;
    for (int i = 1; i < n; i++) {
      int u = p[i-1]-1;
      int v = p[i]-1;
      val &= (d[u]+d[v]-2*d[lca(u,v,d,par)] <= 3);
    }
    cout << val << "\n";


  }
  return 0;
}