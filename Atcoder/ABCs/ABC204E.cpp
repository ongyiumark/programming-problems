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

struct edge {
  int v;
  ll c, d;

  edge(int v, ll c, ll d) : v(v), c(c), d(d) {}
};

void dfs(int u, vector<vector<edge>> &adj, vector<bool> &vis) {
  vis[u] = true;
  for (auto &[v, c, d] : adj[u]) {
    if (vis[v]) continue;
    dfs(v, adj, vis);
  }
}

const ll INF = 1e18;

vector<ll> dijkstra(int s, vector<vector<edge>> &adj) {
  int n = adj.size();
  vector<ll> dist(n, INF);
  priority_queue<tuple<ll, int>> pq;
  dist[s] = 0;
  pq.push({-dist[s], s});

  while(!pq.empty()) {
    auto [w, u] = pq.top();
    pq.pop();
    if (dist[u] < -w) continue;

    for (auto &[v, c, d] : adj[u]) {
      ll cw = 1e18;
      ll lo = dist[u]+1;

      ll hi = d;
      ll ans = lo;
      while (lo <= hi) {
        ll mid = hi - (hi-lo)/2;
        if (mid*mid <= d) {
          ans = mid;
          lo = mid+1;
        }
        else hi = mid-1;
      }

      cw = min(cw, c + d/ans + (ans-dist[u]-1));
      cw = min(cw, c + d/(ans+1) + (ans+1-dist[u]-1));

      if (dist[v] > dist[u] + cw) {
        dist[v] = dist[u] + cw;
        pq.push({-dist[v], v});
      }
    }
  }
  return dist;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m; cin >> n >> m;
  vector<vector<edge>> adj(n, vector<edge>());
  for (int i = 0; i < m; i++) {
    int a, b, c, d; cin >> a >> b >> c >> d;
    a--; b--;
    adj[a].push_back(edge(b,c,d));
    adj[b].push_back(edge(a,c,d));
  }
  
  vector<bool> vis(n);
  dfs(0, adj, vis);
  if (!vis[n-1]) {
    cout << -1 << "\n";
    return 0;
  } 

  vector<ll> dist = dijkstra(0, adj);
  cout << dist[n-1] << "\n";
  return 0;
}
