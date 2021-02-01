/*
  This can be solved with 01BFS, but we need to modify the nodes and edges.

  Each station has its own set of companies, denoted by the lines that connect to it.
  A station-company pair will be our nodes. 
  That is, a line from p to q operated by company c will be (p,c)<->(q,c) with weight 0.

  At each station, we will denote (station, -1) as the transfer node. 
  This node will be connected to all the company lines in that station. 
  Going toward the node has weight 0, but going away from the node has weight 1.
  Imagine this node as the ticket booth. You need to go out and pay another fair when transferring lines.
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

const int N = 1e5;
vector<pii> tadj[N+1];
map<pii, vector<piii>> adj;
map<pii,ll> dist;

void solve(pii s){
  deque<pii> dq;
  dist[s] = 0;
  dq.push_back(s);

  while(!dq.empty()){
    pii u = dq.front();
    dq.pop_front();
    for (auto &e : adj[u]){
      int w = e.first;
      pii v = e.second;
      if (dist.count(v) == 0) dist[v] = 1e9;
      if (dist[u]+w < dist[v]){
        dist[v] = dist[u]+w;
        if (w == 0) dq.push_front(v);
        else dq.push_back(v);
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
    tadj[p].push_back({q,c});
    tadj[q].push_back({p,c});
  }
  for (int u = 1; u <= n; u++){
    for (auto &e : tadj[u]){
      int v = e.first;
      int c = e.second;
      adj[{u,c}].push_back({0, {v,c}});
      adj[{u,c}].push_back({0, {u,-1}});;
      adj[{u,-1}].push_back({1, {u,c}});
    }
  }
  solve({1,-1});
  cout << (dist.count({n,-1}) ? dist[{n, -1}] : -1) << endl;
  return 0;
}
