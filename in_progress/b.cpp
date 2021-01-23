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

vector<pii> adj[N];
map<pii, vector<piii>> nadj;
map<pii, int> dist;

void dijkstra(pii s){
  priority_queue<piii, vector<piii> , greater<piii> > pq;
  dist[s] = 0;
  pq.push({dist[s], s});
  while(!pq.empty()){
    pii u = pq.top().second;
    int d = pq.top().first;
    pq.pop();
    if (dist[u] < d) continue;
    for (auto &e : nadj[u]){
      pii v = e.second;
      int w = e.first;
      if (dist.count(v) == 0) dist[v] = 1e9;
      if (dist[u] + w < dist[v]){
        dist[v] = dist[u]+w;
        pq.push({dist[v], v});
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++){
    int p, q, c;
    cin >> p >> q >> c;
    adj[p].push_back({q, c});
    adj[q].push_back({p, c});
  }

  for (int i = 1; i <= n; i++){
    for (auto &e : adj[i]){
      for (auto &f : adj[i]){
        if (e.first == f.first) continue;
        if (e.second == f.second){
          nadj[{i, e.second}].push_back({0, f});
        }
        else {
          nadj[{i, e.second}].push_back({0, {i, -1}});
          nadj[{i, -1}].push_back({1, f});
        }
      }
    }
  }

  dijkstra({1,-1});
  cout << (dist.count({n,-1}) ? dist[{n,-1}] : -1) << endl;
  return 0;
}
