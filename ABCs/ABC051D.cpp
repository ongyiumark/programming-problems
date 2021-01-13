/*
  Dijkstra from all sources.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct edge{
  int to, w;
};
const int N = 101;
vector<edge> graph[N];
set<pair<int,int>> included;
int n; 

void dijkstra(int i){
  priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int>> > pq;
  vector<int> dist(N, 1e9);
  vector<int> par(N, -1);

  dist[i] = 0;
  pq.push({dist[i], i});

  while(!pq.empty()){
    auto curr = pq.top();
    pq.pop();
    int u = curr.second;
    for (auto e : graph[u]){
      int v = e.to;
      int w = e.w;
      if (dist[u] + w < dist[v]){
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
        par[v] = u;
      }
    }
  }

  for (int x = 1; x <= n; x++){
    int b = x;
    while(par[b] != -1){
      included.insert({min(b, par[b]), max(b, par[b])});
      b = par[b];
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int m; cin >> n >> m;
  for (int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back({b,c});
    graph[b].push_back({a,c});
  }

  for (int i = 1; i <= n; i++){
    dijkstra(i);
  }
  cout << m - included.size() << endl;
  return 0;
}
