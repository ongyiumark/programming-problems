#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

struct dsu {
  vector<int> p;
  dsu(int n) : p(n, -1) {}
  int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
  }

  bool unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return false;
    if (p[a] > p[b]) swap(a, b);

    p[a] += p[b];
    p[b] = a;

    return true;
  }

  bool check(int a, int b) {
    return find(a) == find(b);
  }
};

vector<pair<int,int>> l;
vector<vector<int>> adj;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m; cin >> n >> m;
  l.resize(n); adj.resize(n);
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    l[i] = {x, i};
  }

  for (int i = 0; i < m; i++) {
    int x, y; cin >> x >> y;
    x--; y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }  

  sort(l.begin(), l.end());
  vector<int> dspref(n), dssuff(n);
  
  int num_components = 0;
  vector<bool> vis(n);
  dsu ufpref(n);
  for (int i = 0; i < n; i++) {
    auto [val, id] = l[i];
    vis[id] = true;
    num_components++;
    for (int v : adj[id]) {
      if (!vis[v]) continue; // add only to edges in the left
      if (ufpref.unite(id, v)) num_components--;
    }

    dspref[i] = num_components;
  }
  vector<int> nxt(n);
  for (int i = n-1; i >= 1; i--) {
    if (l[i].first == l[i-1].first) dspref[i-1] = dspref[i];
  }

  nxt[n-1] = n;
  for (int i = n-2; i >= 0; i--) {
    nxt[i] = i+1;
    if (l[i].first == l[i+1].first) nxt[i] = nxt[i+1];
  }

  num_components = 0;
  vector<bool>(n, 0).swap(vis);
  dsu ufsuff(n);
  for (int i = n-1; i >= 0; i--) {
    auto [val, id] = l[i];
    vis[id] = true;
    num_components++;
    for (int v : adj[id]) {
      if (!vis[v]) continue; // add only to edges in the right
      if (ufsuff.unite(id, v)) num_components--;
    }

    dssuff[i] = num_components;
  }
  for (int i = 0; i < n-1; i++) {
    if (l[i].first == l[i+1].first) dssuff[i+1] = dssuff[i];
  }

  for (int i = 0; i < n-1; i++) {
    if (nxt[i] < n && dspref[i] + dssuff[nxt[i]] <= min(nxt[i], n-nxt[i]) + 1) {
      cout << l[i].first << "\n";
      return 0;
    }
  }
  cout << -1 << "\n";


  
  return 0;
}