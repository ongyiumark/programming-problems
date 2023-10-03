#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll modpow(ll b, ll e, ll p) {
  ll ans = 1;
  while(e > 0) {
    if (e&1) ans = (ans*b)%p;
    b = (b*b)%p;
    e >>= 1;
  }
  return ans;
}

bool dfs(int u, vector<int> &d, vector<vector<int>> &adj) {
  bool ocycle = false;
  for (int v : adj[u]) {
    if (d[v] >= 0) {
      if (abs(d[v]-d[u])%2 == 0) ocycle = true;
    }
    else {
      d[v] = d[u]+1;
      ocycle |= dfs(v, d, adj);
    }
  }
  return ocycle;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, p; cin >> n >> m >> p;
  vector<vector<int>> adj(n, vector<int>());

  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    u--; v--;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> d(n, -1);
  bool ocycle = false;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (d[i] >= 0) continue;
    cnt++;
    d[i] = 0;
    ocycle |= dfs(i, d, adj);
  }

  if (ocycle) cout << "impossible\n";
  else {
    int ans = modpow(2, cnt-1, p);
    cout << (ans+1)%p << "\n";
  }
  
  return 0;
}