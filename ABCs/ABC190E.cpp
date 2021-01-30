/*
  It's possible to form a sequence of gems if the kinds are connected.
  We can check this with dfs.
  
  Next, we want to know the pairwise distances between the k kinds.
  We can compute this with bfs from each source.

  We want to compute for the shortest path to visit all k nodes.
  We can do this with bitmask dp.
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
int a[N], b[N], c[17];
vector<int> adj[N];
bool vis[N];
ll dist[17][N], ndist[17][17];

ll dp[17][(1<<17)];
int k;
ll solve(int i, int bitmask){
  ll &ret = dp[i][bitmask];
  if (ret != -1) return ret;
  if (bitmask == (1<<k)-1) return ret = 0;
  ret = 1e18;
  for (int j = 0; j < k; j++){
    if (bitmask&(1<<j)) continue;
    ret = min(ret, ndist[i][j]+solve(j, bitmask|(1<<j)));
  }
  return ret;
}

void bfs(int i){
  int s = c[i];
  queue<int> q;
  q.push(s);
  memset(vis, 0, sizeof vis);
  vis[s] = 1;
  dist[i][s] = 0;

  while(!q.empty()){
    int u = q.front();
    q.pop();
    for (int v : adj[u]){
      if (vis[v]) continue;
      vis[v] = 1;
      q.push(v);
      dist[i][v] = dist[i][u]+1;
    }
  }
}

void dfs(int u){
  vis[u] = 1;
  for (int v : adj[u]){
    if (vis[v]) continue;
    dfs(v);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++){
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
    adj[a[i]].push_back(b[i]);
    adj[b[i]].push_back(a[i]);
  }
  cin >> k;
  for (int i = 0; i < k; i++){
    cin >> c[i];
    c[i]--;
  }

  memset(vis, 0, sizeof vis);
  dfs(c[0]);
  for (int i = 0; i < k; i++){
    if (!vis[c[i]]){
      cout << -1 << endl;
      return 0;
    }
  }

  memset(dist, 63, sizeof dist);
  for (int i = 0; i < k; i++){
    bfs(i);
  }
  
  for (int i = 0; i < k; i++){
    for (int j = i+1; j < k; j++){
      ndist[i][j] = dist[i][c[j]];
      ndist[j][i] = dist[j][c[i]];
    }
  }

  memset(dp, -1, sizeof dp);
  ll ans = 1e18;
  for (int i = 0; i < k; i++){
    ans = min(ans,solve(i, 1<<i));
  }
  cout << ans+1 << endl;
  return 0;
}
