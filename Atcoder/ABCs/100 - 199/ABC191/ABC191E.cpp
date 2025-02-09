/*
  All sources dijkstra is enough to solve the problem.
  Use an adjacency list. Don't use an adjacency matrix or it'll be too slow.
*/
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

const int N = 2000;

struct edge{
  int to, w;
};
vector<edge> adj[N];
int dist[N][N];
int self[N];

void dijkstra(int s){
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  dist[s][s] = 0;
  pq.push({dist[s][s], s});
  while(!pq.empty()){
    int u = pq.top().second;
    int d = pq.top().first;
    pq.pop();
    if (dist[s][u] < d) continue;
    for (edge &e : adj[u]){
      int v = e.to;
      int w = e.w;
      if (dist[s][u] + w < dist[s][v]){
        dist[s][v] = dist[s][u] + w;
        pq.push({dist[s][v], v});
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  memset(self, 63, sizeof self);
  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++){
    int a, b, c; cin >> a >> b >> c;
    a--; b--;
    adj[a].push_back({b,c});
    if (a==b) self[a] = min(self[a], c);
  }

  memset(dist,63,sizeof dist);
  for (int i = 0; i < n; i++) dijkstra(i);

  for (int i = 0; i < n; i++){
    int cost = self[i];
    for (int j = 0; j < n; j++){
      if (i == j) continue;
      cost = min(cost, dist[i][j] + dist[j][i]);
    }
    cout << (cost >= 1e9 ? -1 : cost) << endl;
  }
  return 0;
}
