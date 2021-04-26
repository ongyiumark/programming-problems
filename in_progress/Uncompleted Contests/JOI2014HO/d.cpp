/*
  Dijkstra with modified weights.
  Just keep track of the current height for each state.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,ll> pii;
typedef pair<ll,pair<int,ll>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5+1;
const int M = 3e5;
int n, m;
int H[N];
vector<pii> adjlist[N];
ll x;

ll dist[N];

void dijkstra(int s){
  memset(dist, 31, sizeof dist);
  priority_queue<piii, vector<piii>, greater<piii> >pq;
  dist[s] = 0;
  pq.push({dist[s], {s,x}});
  ll to_top = 0;
  while(!pq.empty()){
    int u = pq.top().second.first;
    int cx = pq.top().second.second;
    int d = pq.top().first;
    pq.pop();
    if (dist[u] < d) continue;
    for (auto &e : adjlist[u]){
      int v = e.first;
      ll w = e.second;
      ll add = 0;
      ll nx = cx-w;
      if (H[u] < w) continue;
      if (cx-w < 0) {
        add = w-cx;
        nx = 0;
      }
      if (cx-w > H[v]) {
        add = cx-w-H[v]; 
        nx = H[v];
      }
      if (dist[u]+w+add < dist[v]){
        dist[v] = dist[u]+w+add;
        pq.push({dist[v],{v,nx}});
        if (v == n) to_top = H[v]-nx;
      }
    }
  }

  ll ans = dist[n]+to_top;
  cout << (ans > 1e18 ? -1 : ans) << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> x;
  for (int i = 1; i <= n; i++) cin >> H[i];
  for (int i = 0; i < m; i++){
    int a, b;
    ll t;
    cin >> a >> b >> t;
    adjlist[a].push_back({b,t});
    adjlist[b].push_back({a,t});
  }

  dijkstra(1);
  return 0;
}
