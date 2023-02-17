// Just djikstra.

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct edge {
  ll to, w, k;
};
const int N = 1e5+5;
vector<edge> graph[N];
ll dist[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, m, x, y; cin >> n >> m >> x >> y;
  x--; y--;
  for (int i = 0; i < m; i++) {
    ll a, b, t, k; cin >> a >> b >> t >> k;
    a--; b--;
    graph[a].push_back({b,t,k});
    graph[b].push_back({a,t,k});
  }

  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>> > pq;
  memset(dist, 15, sizeof dist);

  ll INF = dist[0];
  dist[x] = 0;
  pq.push({dist[x], x});

  while(!pq.empty()) {
    auto [ww, u] = pq.top();
    pq.pop(); 
    if (dist[u] < ww) continue;

    for (auto [v, w, k] : graph[u]) {
      if (dist[v] > (dist[u]+k-1)/k*k + w) {
        dist[v] = (dist[u]+k-1)/k*k + w;
        pq.push({dist[v], v});
      }
    }
  }

  cout << (dist[y] >= INF ? -1 : dist[y]) << "\n";

  return 0;
}
