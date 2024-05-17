#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6+5;
int main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<int> lpf(N);
  vector<bool> isc(N);
  for (int i = 2; i < N; i++) {
    if (isc[i]) continue;
    lpf[i] = i;
    for (int j = 2*i; j < N; j += i) {
      isc[j] = true;
      if (lpf[j] == 0) lpf[j] = i;
    }
  }

  int n; cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  vector<vector<int>> adj(n);
  for (int i = 0; i < n-1; i++) {
    int u, v; cin >> u >> v;
    u--; v--;
    if (a[u] == 1 || a[v] == 1) continue;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  map<int,vector<int>> cnt;
  for (int i = 0; i < n; i++) {
    int x = a[i];
    while (x > 1) {
      int p = lpf[x];
      cnt[p].push_back(i);
      while (x % p == 0) x /= p;
    }
  }
  
  int ans = 0;
  for (auto &[p, nodes] : cnt) {
    int sz = nodes.size();
    vector<bool> vis(sz);
    map<int,int> idx;
    for (int i = 0; i < sz; i++) idx[nodes[i]] = i;

    function<int(int, int)> dfs = [&](int u, int parent) {
      vis[idx[u]] = 1;
      int ret = 1;
      for (int &v : adj[u]) {
        if (v == parent) continue;
        if (a[v] % p != 0) continue;
        ret += dfs(v, u); 
      }
      return ret;
    };

    int current = 0;
    for (int i = 0; i < sz; i++) {
      if (vis[i]) continue;
      current = max(current, dfs(nodes[i], -1));
    }
    ans = max(current, ans);
  }
  cout << ans << "\n";


  return 0;
}