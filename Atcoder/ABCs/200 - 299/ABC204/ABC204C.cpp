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

int bfs(int s, vector<vector<int>> &adj) {
  int n = adj.size();
  vector<bool> vis(n);

  queue<int> q;
  q.push(s);
  vis[s] = true;

  while(!q.empty()) {
    int u = q.front();
    q.pop();

    for (int &v : adj[u]) {
      if (vis[v]) continue;
      q.push(v);
      vis[v] = true;
    }
  }

  return count_if(vis.begin(), vis.end(), [](const bool& x) { return x; });
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m; cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    u--; v--;
    adj[u].push_back(v);
  }
  
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += bfs(i, adj);
  }
  cout << ans << "\n";
  return 0;
}
