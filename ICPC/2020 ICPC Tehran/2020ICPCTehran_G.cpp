#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;

const ll INF = 1e18;
vector<vector<ii>> adj;
vector<ll> dp;
int n, m;


vector<ll> dijkstra(int s) {
  int n = adj.size();
  vector<ll> d(n, INF);

  priority_queue<ii, vector<ii>, greater<ii>> pq;
  d[s] = 0;
  pq.push({d[s], s});
  while (!pq.empty()) {
    auto [cw, u] = pq.top();
    pq.pop();

    if (d[u] < cw) continue;
    for (auto &[v, w] : adj[u]) {
      if (d[v] > d[u]+w) {
        d[v] = d[u]+w;
        pq.push({d[v], v});
      }
    } 
  }
  return d;
}

void dfs(int u, int s, int t, vector<int> &par, vector<ll> &d, vector<ll> &res) {
  if (u == t) {
    int v = t;
    ll mask = 0;
    mask |= (1<<v);
    while (v != s) {
      v = par[v];
      mask |= (1<<v);
    }
    res.push_back(mask);
    return;
  }

  for (auto &[v, w] : adj[u]) {
    if (d[v] != d[u]+w) continue;
    par[v] = u;
    dfs(v, s, t, par, d, res);
    par[v] = -1;
  }
}

vector<ll> get_paths(int s, int t, vector<ll> &d) {
  int n = adj.size();
  vector<int> par(n, -1);
  vector<ll> res;
  
  dfs(s, s, t, par, d, res);
  return res;
}

string mask_to_string(ll mask) {
  ostringstream s;
  for (int i = 0; i < n; i++) {
    s << ((mask>>i)&1);
  }
  string res = s.str();
  reverse(res.begin(), res.end());
  return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    adj.resize(n, vector<ii>());
    for (int i = 0; i < m; i++) {
      int u, v; ll w; cin >> u >> v >> w;
      u--; v--;
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }
    int s1, t1, s2, t2; cin >> s1 >> t1 >> s2 >> t2;
    s1--; t1--; s2--; t2--;
    vector<ll> d1 = dijkstra(s1);
    vector<ll> d2 = dijkstra(s2);

    vector<ll> p1 = get_paths(s1, t1, d1);
    vector<ll> p2 = get_paths(s2, t2, d2);

    dp.resize(1<<n, 0);
    for (ll mask : p2) dp[mask] = 1;
    for (int i = 0; i < n; i++) {
      for (ll mask = 0; mask < (1<<n); mask++) {
        if (mask&(1<<i)) {
          dp[mask] += dp[mask^(1<<i)];
        }
      }
    }

    ll ans = 0;
    for (ll mask : p1) {
      ll cmask = (1<<n)-1-mask;
      ans += dp[cmask];
    }
    cout << ans << "\n";


    return 0;
}