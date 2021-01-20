/*
  Dijkstra from K. 
  On second thought, DFS/BFS from K would also work since it's a tree.
  Though, the dijkstra solution suprisingly worked.
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

const int N = 1e5;
vector<pair<int,int>> adj[N];
ll dist[N];

void dfs(int u, int p, ll d){
  dist[u] = d;
  for (auto &e : adj[u]){
    int v = e.first;
    ll w = e.second;
    if (v == p) continue;
    dfs(v, u, d+w);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  for (int i = 0; i < n-1; i++){
    int a, b, c; cin >> a >> b >> c;
    a--; b--;
    adj[a].push_back({b,c});
    adj[b].push_back({a,c});
  }
 
  int q, k;
  cin >> q >> k;
  memset(dist, 0, sizeof dist);
  dfs(--k,-1, 0);
  while(q--){
    int x, y;
    cin >> x >> y;
    x--; y--;
    cout << dist[x]+dist[y] << endl;
  }
  return 0;
}
