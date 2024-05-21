/*
  If Kenkoooo converts his money at city i, this is equivalent to the cost of yen from s to i plus the cost of snuk from t to i.
  We can do two dijktras: one from s and one from t.

  Then, we can have a prefix minimum starting from city n.
  This is because at year i, he can only exchange at cities [i,n].
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

struct edge{
  ll to, a, b;
};
const int N = 1e5+5;
vector<edge> adj[N];
ll dist[N];
ll dist_start[N], dist_end[N];
ll min_pref[N];

void dijkstra(int s, bool yen){
  memset(dist, 31, sizeof dist);
  priority_queue<pair<ll, int>, vector<pair<ll,int>>, greater<pair<ll,int>> > pq;
  dist[s] = 0;
  pq.push({dist[s], s}); 
  while(!pq.empty()){
    int u = pq.top().second;
    ll d = pq.top().first;
    pq.pop();
    if (dist[u] < d) continue;

    for (edge &e : adj[u]){
      int v = e.to;
      ll w = (yen ? e.a : e.b);
      if (dist[u]+w < dist[v]){
        dist[v] = dist[u]+w;
        pq.push({dist[v], v});
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, m, s, t; cin >> n >> m >> s >> t;
  for (int i = 0; i < m; i++){
    ll u, v, a, b;
    cin >> u >> v >> a >> b;

    adj[u].push_back({v,a,b});
    adj[v].push_back({u,a,b});
  }

  dijkstra(s, 1);
  copy(dist, dist+n+1, dist_start);
  dijkstra(t, 0);
  copy(dist, dist+n+1, dist_end);

  for (int i = n; i >= 1; i--){
    min_pref[i] = dist_start[i]+dist_end[i];
    if (i < n) min_pref[i] = min(min_pref[i], min_pref[i+1]);
  }

  for (int i = 1; i <= n; i++){
    ll snuk = 1e15;
    cout << snuk-min_pref[i] << endl;
  }
  return 0;
}
