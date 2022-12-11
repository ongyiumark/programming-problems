#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ll,int> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 500;
const ll INF = 1e18;

struct edge {
  int u, v; ll cost, cap, flow;
  edge(int u, int v, ll cap, ll cost) :
    u(u), v(v), cap(cap), cost(cost), flow(0) {}
};

struct flow_network {
  int n, s, t;
  vector<int> par, in_queue, num_vis;
  vector<ll> dist, pot;
  vector<edge> edges;
  vector<vector<int>> adj;
  map<pair<int,int>, vector<int>> edge_idx;

  flow_network(int n, int s, int t) : n(n), s(s), t(t) {
    vector<vector<int>>(n).swap(adj);
    vector<int>(n).swap(par);
    vector<int>(n).swap(in_queue);
    vector<int>(n).swap(num_vis);
    vector<ll>(n).swap(dist);
    vector<ll>(n).swap(pot);
    for (int u = 0; u < n; ++u) pot[u] = 0;
  }

  void add_edge(int u, int v, ll cap, ll cost) {
    adj[u].push_back(edges.size());
    edge_idx[{u,v}].push_back(edges.size());
    edges.push_back(edge(u,v,cap,cost));
    adj[v].push_back(edges.size());
    edge_idx[{u,v}].push_back(edges.size());
    edges.push_back(edge(v,u, 0LL, -cost));
  }

  ll get_flow(int u, int v) {
    ll f = 0;
    for (int i : edge_idx[{u,v}]) f += edges[i].flow;
    return f;
  }

  ll res(edge &e) {
    return e.cap - e.flow;
  }

  void bellman_ford() {
    for (int u = 0; u < n; ++u) pot[u] = INF;
    pot[s] = 0;
    for (int it = 0; it < n-1; ++it) {
      for (auto e : edges) {
        if (res(e) > 0) {
          pot[e.v] = min(pot[e.v], pot[e.u] + e.cost);
        }
      }
    }
  }

  bool spfa() {
    // queue<int> q; q.push(s);
    // while(!q.empty()) {
    //   int u = q.front(); q.pop(); in_queue[u] = 0;
    //   if (++num_vis[u] >= n) {
    //     dist[u] = -INF;
    //     return false;
    //   }
    //   for (int i : adj[u]) {
    //     edge e = edges[i];
    //     if (res(e) <= 0) continue;
    //     ll nd = dist[u] + e.cost + pot[u] - pot[e.v];
    //     if (dist[e.v] > nd) {
    //       dist[e.v] = nd;
    //       par[e.v] = i;
    //       if (!in_queue[e.v]) {
    //         q.push(e.v);
    //         in_queue[e.v] = 1;
    //       }
    //     } 
    //   }
    // }


    for (int u = 0; u < n; ++u) {
      dist[u] = INF;
    }
    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>>  pq;
    pq.push({0, s});
    while(!pq.empty()) {
      int u = pq.top().second;
      ll d = pq.top().first;
      pq.pop();
      if (dist[u] < d) continue;
      dist[u] = d;

      for (int i : adj[u]) {
        edge e = edges[i];
        if (res(e) <= 0) continue;
        ll nd = dist[u] + e.cost + pot[u] - pot[e.v];
        if (dist[e.v] > nd) {
          dist[e.v] = nd;
          par[e.v] = i;
          pq.push({nd, e.v});
        } 
      }
    }
    return dist[t] != INF;
  }

  bool aug_path() {
    for (int u = 0; u < n; ++u) {
      par[u] = -1;
      in_queue[u] = 0;
      num_vis[u] = 0;
      dist[u] = INF;
    }
    dist[s] = 0;
    in_queue[s] = 1;
    return spfa();
  }

  pair<ll,ll> calc_max_flow(bool do_bellman_ford=false) {
    ll total_cost = 0, total_flow = 0;
    if (do_bellman_ford) bellman_ford();
    while(aug_path()) {
      ll f = INF;
      for (int i = par[t]; i != -1; i = par[edges[i].u]) {
        f = min(f, res(edges[i]));
      }
      for (int i = par[t]; i != -1; i = par[edges[i].u]) {
        edges[i].flow += f;
        edges[i^1].flow -= f;
      }
      total_cost += f * (dist[t] + pot[t] - pot[s]);
      total_flow += f;

      for (int u = 0; u < n; ++u) {
        if (par[u] != -1) pot[u] += dist[u];
      }
    }
    return {total_cost, total_flow};
  }
};


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  ll l[n+1][n+1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> l[i][j];
    }
  }

  ll source = N+1;
  ll sink = N+2;
  flow_network network(N+5, source, sink);
  for (int i = 1; i <= n; i+=2) {
    for (int j = 1; j <= n; j+=2) {
      // city i at position j
      ll cost = 0;
      if (j+1 <= n) cost += l[i][j+1];
      if (j-1 >= 1) cost += l[j-1][i];
      
      network.add_edge((i+1)/2, (N+j+1)/2, 1e18, cost);
    }
  }
  for (int i = 1; i <= n; i+= 2) {
    network.add_edge(source, (i+1)/2, 1, 0);
    network.add_edge((i+N+1)/2, sink, 1, 0);
  }

  cout << network.calc_max_flow(false).first << endl;


  return 0;
}
