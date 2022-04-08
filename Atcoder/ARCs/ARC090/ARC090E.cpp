/*
  Count the number of pairs of shortest paths.
  Subtract the pairs where they meet on a vertex.
  Subtract the pairs where they meet on an edge.

  These can be computed with dijkstra then DP.
    DP[u] += DP[v] if dist[v]+d = dist[u]
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,ll> pii;
typedef pair<ll,pair<int,int>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int maxN = 1e5+5;
const int maxM = 2e5+5;
const ll INF = 1e18;
const ll MOD = 1e9+7;

piii edges[maxM];
vector<pii> graph[maxN];

ll dpS[maxN], dpT[maxN];
vector<ll> dS, dT;

int n, m;
int s, t;

vector<ll> dijkstra(int start) {
  priority_queue< pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>> > pq;
  vector<ll> dist(n+1, INF);

  dist[start] = 0; 
  pq.push({dist[start],start});

  while(!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (dist[u] < d) continue;
    
    dist[u] = d;
    for (auto [v, w] : graph[u]) {
      if (dist[u]+w < dist[v]){
        dist[v] = dist[u]+w;
        pq.push({dist[v],v});
      }
    }
  }
  return dist;
} 

ll solveS(int u) {
  ll &ans = dpS[u];
  if (ans != -1) return ans;
  if (u == s) return 1;
  
  ans = 0;
  for (auto [v,d] : graph[u]) {
    if (dS[v]+d == dS[u]) {
      ans += solveS(v);
    }
  }
  ans %= MOD;
  return ans;
}

ll solveT(int u) {
  ll &ans = dpT[u];
  if (ans != -1) return ans;
  if (u == t) return 1;
  
  ans = 0;
  for (auto [v,d] : graph[u]) {
    if (dT[v]+d == dT[u]) {
      ans += solveT(v);
    }
  }
  ans %= MOD;
  return ans;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  cin >> s >> t;
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    ll d; cin >> d;

    edges[i] = {d,{u,v}};
    graph[u].push_back({v,d});
    graph[v].push_back({u,d});
  }

  dS = dijkstra(s);
  dT = dijkstra(t);

  memset(dpS, -1, sizeof dpS);
  memset(dpT, -1, sizeof dpT);

  ll STD = dS[t];
  ll total = solveS(t)*solveS(t)%MOD;
  ll vertex_meet = 0;
  for (int i = 1; i <= n; i++) {
    if (dS[i] == dT[i] && STD == 2*dS[i]) {
      ll tmp = solveS(i)*solveT(i)%MOD;
      vertex_meet += tmp*tmp%MOD;
    } 
  }
  vertex_meet %= MOD;

  ll edge_meet = 0;
  for (int i = 0; i < m; i++) {
    auto [d, p] = edges[i];
    auto [u, v] = p;

    if (2*dS[u] < STD && 2*dT[v] < STD && dS[u]+dT[v]+d == STD){
      ll tmp = solveS(u)*solveT(v)%MOD;
      edge_meet += tmp*tmp%MOD;
    }
    swap(u,v);
    if (2*dS[u] < STD && 2*dT[v] < STD && dS[u]+dT[v]+d == STD){
      ll tmp = solveS(u)*solveT(v)%MOD;
      edge_meet += tmp*tmp%MOD;
    }
    swap(u,v);
  }
  edge_meet %= MOD;

  ll ans = total - vertex_meet - edge_meet;
  ans %= MOD;
  if (ans < 0) ans += MOD;
  cout << ans << endl;
  
  return 0;
}
