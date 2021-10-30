/*
  If the intersection is reachable within half the maximum distance, 
    then we can go through all the streets connected to that intersection.
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

const int N = 1e5+5;
vector<pair<int,int>> graph[N];
int I, S, L, U;

vector<bool> dijkstra(int s){
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  int dist[I];
  memset(dist, 31, sizeof dist);

  dist[s] = 0;
  pq.push({s,dist[s]});

  while(!pq.empty()){
    int u = pq.top().first;
    int d = pq.top().second;
    pq.pop();
    if (dist[u] < d) continue;
    for (auto p : graph[u]){
      int v = p.first;
      int w = p.second;
      if (dist[v] > dist[u] + w){
        dist[v] = dist[u]+w;
        pq.push({v, dist[v]});
      }
    }
  }

  vector<bool> res(I, 0);
  for (int i = 0; i < I; i++){
    res[i] = (dist[i] < U);
  }
  return res;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> I >> S >> L >> U;

  for (int i = 0; i < S; i++){
    int u, v, w; cin >> u >> v >> w;
    graph[u].push_back({v,2*w});
    graph[v].push_back({u,2*w});
  }

  vector<bool> reachable = dijkstra(0);
  set<pair<int,int>> ans;
  for (int u = 0; u < I; u++){
    if (!reachable[u]) continue;
    for (pair<int,int> p: graph[u]){
      int v = p.first;
      ans.insert({min(u,v), max(u,v)});
    }
  }

  cout << ans.size() << endl;
  return 0;
}
