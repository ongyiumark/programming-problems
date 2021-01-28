/*
  Classic max flow problem.
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

const int N = 101;
int cap[N][N];
int flow[N][N];

bool vis[N];
int par[N];

void dfs(int u, int n){
  vis[u] = 1;
  for (int v = 1; v <= n; v++){
    if (cap[u][v]-flow[u][v] > 0 && !vis[v]){
      par[v] = u;
      dfs(v, n);
    }
  }
}

void find_path(int s, int n){
  memset(vis, 0, sizeof vis);
  memset(par, -1, sizeof par);
  dfs(s,n);
}
int solve(int s, int t, int n){
  while(true){
    find_path(s,n);
    if (par[t] == -1) break;
    int x = t;
    vector<int> path;
    while(x != -1){
      path.push_back(x);
      x = par[x];
    }
    reverse(path.begin(), path.end());

    int bottleneck = 1e9;
    for (int i = 0; i+1 < path.size(); i++){
      int u = path[i];
      int v = path[i+1];
      bottleneck = min(bottleneck, cap[u][v]-flow[u][v]);
    }
    for (int i = 0; i+1 < path.size(); i++){
      int u = path[i];
      int v = path[i+1];
      flow[u][v]+=bottleneck;
      flow[v][u]-=bottleneck;
    }
  }

  int ret = 0;
  for (int i = 1; i <= n; i++){
    ret += flow[i][t];
  }
  return ret;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int network = 1;
  while(true){
    int n; cin >> n;
    if (n == 0) break;
    memset(cap, 0, sizeof cap);
    memset(flow, 0, sizeof flow);
    
    int s, t, c;
    cin >> s >> t >> c;
    for (int i = 0; i < c; i++){
      int u, v, b;
      cin >> u >> v >> b;
      cap[u][v] += b;
      cap[v][u] += b;
    }

    int ans = solve(s, t, n);
    cout << "Network " << network << endl;
    cout << "The bandwidth is " << ans << "." << endl;
    cout << endl;
    network++;
  }
  return 0;
}
