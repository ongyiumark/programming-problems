#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5+5;
struct edge {
  int u, v;
  ll w;
};

vector<int> graph[N];
ll t[N];
vector<int> toposort;
bool vis[N];
ll dist[N];
bool ans[N];

void djikstra(int s) {
  priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>> > pq;
  dist[s] = t[s];
  pq.push({dist[s], s});
  while(!pq.empty()) {
    ll w = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    if (dist[u] < w) continue;
    for (int v : graph[u]) {
      if (dist[v] > dist[u]+t[v]) {
        dist[v] = dist[u]+t[v];
        pq.push({dist[v], v});
      }
    }
  } 
}

void dfs(int u) {
  vis[u] = 1;

  for (int v : graph[u]) {
    if (dist[v] == dist[u]+t[v]){
      if (vis[v]) continue;
      dfs(v);
    }
  }
  toposort.push_back(u);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, k; cin >> n >> m >> k;
  for (int i = 0; i < n; i++) cin >> t[i];
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    u--; v--;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  memset(dist, 31, sizeof dist);
  djikstra(0);
  memset(vis, 0, sizeof vis);
  dfs(0);

  if (n == 2 && k == 1) {
    cout << "impossible" << endl;
    return 0;
  }
  
  // Direct edge
  bool direct = 0;
  if (dist[0] + t[n-1] == dist[n-1]) {
    if (k >= 2) {
      ans[0] = ans[n-1] = 1;
      k -= 2;
    }
    else ans[0] = ans[n-1] = 0;
    direct = 1;
  }

  
  for (int i = 0; i < n; i++) {
    if (direct) {
      if (toposort[i] == 0 || toposort[i] == n-1) continue;
    }
    if (k > 0) {
      ans[toposort[i]] = 1;
      k--;
    }
    else ans[toposort[i]] = 0;
  }

  for (int i = 0; i < n; i++) {
    cout << (ans[i] ? 'N' : 'S');
  }
  cout << endl;

  
  return 0;
}
