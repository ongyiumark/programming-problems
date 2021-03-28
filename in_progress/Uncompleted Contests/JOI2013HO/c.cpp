/*
  Modified Dijkstra. Think of the rooms with switches as possible turning points.
  We simply need to create edges between switch rooms in the same row/col, keeping track of our previous direction.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,ll> pii;
typedef pair<pair<int,int>, int> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5;
const int K = 2e5+5;
int m, n;
int x[K], y[K];
vector<pii> adj[K];
ll dist[K][2];

piii xsort[K], ysort[K];
void dijkstra(int s){
  memset(dist, 15, sizeof dist);
  priority_queue<pair<ll,pair<int,int>>, vector<pair<ll,pair<int,int>>>, greater<pair<ll,pair<int,int>>> > pq;
  dist[s][0] = 0;
  pq.push({dist[s][0], {s,0}});
  while(!pq.empty()){
    int u = pq.top().second.first;
    int dir = pq.top().second.second;
    ll d = pq.top().first;
    pq.pop();
    if (dist[u][dir] < d) continue;
    for (auto e : adj[u]){
      int v = e.first;
      ll w = e.second;
      
      int ndir = 0;
      if (x[u] == x[v] && y[u] == y[v]) ndir = dir;
      else if (x[u] == x[v]) ndir = 0;
      else ndir = 1;

      if (dir != ndir) w++;
      if (dist[u][dir] + w < dist[v][ndir]){
        dist[v][ndir] = dist[u][dir]+w;
        pq.push({dist[v][ndir], {v,ndir}});
      }
    }
  }
  ll ans = min(dist[K-1][0], dist[K-1][1]);
  cout << (ans > 1e18 ? -1 : ans) << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int k; cin >> m >> n >> k;
  for (int i = 0; i < k; i++){
    cin >> x[i] >> y[i];
    xsort[i] = {{x[i], y[i]}, i};
    ysort[i] = {{y[i], x[i]}, i};
  }
  sort(xsort, xsort+k);
  sort(ysort, ysort+k);
  x[K-1] = m; y[K-1] = n;
  x[K-2] = 1; y[K-2] = 1;
  
  // add edge to the end
  if (xsort[k-1].first.first == m){
    int u = xsort[k-1].second;
    int v = K-1;
    int w = n - xsort[k-1].first.second;
    adj[u].push_back({v,w});
  }
  if (ysort[k-1].first.first == n){
    int u = ysort[k-1].second;
    int v = K-1;
    int w = m - ysort[k-1].first.second;
    adj[u].push_back({v,w});
  }

  // add edge to the start
  if (xsort[0].first.first == 1){
    int u = xsort[0].second;
    int v = K-2;
    int w = xsort[0].first.second-1;
    adj[v].push_back({u,w});
  }

  for (int i = 1; i < k; i++){
    if (xsort[i].first.first == xsort[i-1].first.first){
      int u = xsort[i].second;
      int v = xsort[i-1].second;
      int w = abs(xsort[i].first.second - xsort[i-1].first.second);
      adj[u].push_back({v,w});
      adj[v].push_back({u,w});
    }
    
    if (ysort[i].first.first == ysort[i-1].first.first){
      int u = ysort[i].second;
      int v = ysort[i-1].second;
      int w = abs(ysort[i].first.second - ysort[i-1].first.second);
      adj[u].push_back({v,w});
      adj[v].push_back({u,w});
    }
  }
  dijkstra(K-2);
  return 0;
}
