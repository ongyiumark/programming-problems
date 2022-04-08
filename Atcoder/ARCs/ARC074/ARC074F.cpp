/*
  Min s-t cut max flow problem on a bipartite graph. 
  This implementation of Ford-Fulkerson is super scuffed.

  Recommended to use Edmonds-Karp (bfs instead of dfs).
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

const int N = 100;
int cap[2*N+2][2*N+2], flow[2*N+2][2*N+2];
int par[2*N+2], vis[2*N+2];
int sidx = 2*N;
int tidx = 2*N+1;

void dfs(int u, int p){
  par[u] = p;
  vis[u] = 1;
  if (u == tidx) return;
  for (int v = 0; v < 2*N+2; v++){
    if (v == p) continue;
    if (vis[v]) continue;
    if (cap[u][v]-flow[u][v] > 0){
      dfs(v,u);
    }
  }
  vis[u] = 2;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int h, w; cin >> h >> w;
  char grid[h][w];
  pii s, t;
  vector<pii> leafs;
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      cin >> grid[i][j];
      if (grid[i][j] == 'S') s = {i,j};
      if (grid[i][j] == 'T') t = {i,j};
      if (grid[i][j] == 'o') leafs.push_back({i,j});
    }
  }

  if (s.first == t.first || s.second == t.second){
    cout << -1 << endl;
    return 0;
  }

  int n = leafs.size();
  memset(cap, 0, sizeof cap);
  memset(flow, 0, sizeof flow);

  cap[sidx][s.first] = cap[s.first][sidx] = cap[s.second+N][sidx] = cap[sidx][s.second+N] = 1e9;
  cap[tidx][t.first] = cap[t.first][tidx] = cap[t.second+N][tidx] = cap[tidx][t.second+N] = 1e9;
  for (int i = 0; i < n; i++){
    int u = leafs[i].first;
    int v = leafs[i].second;
    v += N;
    cap[u][v] = cap[v][u] = 1;
  }

  while(true){
    memset(par, -1, sizeof par);
    memset(vis, 0, sizeof vis);
    dfs(sidx, -1);
    int v = tidx;
    int bottleneck = 1e9;
    while(par[v] != -1){
      bottleneck = min(bottleneck, cap[par[v]][v]-flow[par[v]][v]);
      v = par[v];
    }
    if (v != sidx) break;

    v = tidx;
    while(par[v] != -1){
      flow[par[v]][v] += bottleneck;
      flow[v][par[v]] -= bottleneck;
      v = par[v];
    }
  }

  int ans = 0;
  for (int i = 0; i < 2*N+2; i++){
    ans += flow[i][tidx];
  }
  cout << ans << endl;
  
  return 0;
}
