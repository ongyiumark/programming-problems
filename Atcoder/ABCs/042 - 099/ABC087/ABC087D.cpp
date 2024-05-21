/*
  We can treat all the connected components separately.
  
  If we fix one element of a connected component, we can compute for the values of the rest.
  We can do this with DFS. How? Notice that an edge of (L,R,D) implies an edge of (R,L,-D).
  
  For each node, we have the following states:
    (1) univisited
    (2) currently visiting
    (3) visited
  
  Everytime we encounter an already visited node, we check if the values match.
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

const int N = 1e5+5;
vector<pii> adj[N];
int vis[N];
int dist[N];

bool dfs_helper(int u){
  vis[u] = 1;
  for (auto &e : adj[u]){
    int v = e.first;
    int w = e.second;
    if (vis[v] == 1) continue;
    if (vis[v] == 2){
      if (dist[v] != dist[u] + w) return false;
      continue;
    }
    dist[v] = dist[u] + w;
    if (!dfs_helper(v)) return false;
  }
  vis[u] = 2;
  return true;
}

bool dfs(int n){
  memset(vis, 0, sizeof vis);
  memset(dist, 0, sizeof dist);
  for (int i = 1; i <= n; i++){
    if (vis[i] == 2) continue;
    dist[i] = 0;
    if(!dfs_helper(i)) return false;
  }
  return true;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++){
    int l, r, d;
    cin >> l >> r >> d;
    adj[l].push_back({r,d});
    adj[r].push_back({l,-d});
  }

  cout << (dfs(n) ? "Yes" : "No") << endl;
  return 0;
}
