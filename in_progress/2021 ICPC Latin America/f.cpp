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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m; cin >> n >> m;
  vector<vector<int>> adj_list(n);
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    u--; v--;
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
  }

  string res; res.append(n, 'A');

  stack<int> to_explore;
  to_explore.push(n-2);
  vector<bool> vis(n);
  vis[n-2] = true;
  while (to_explore.size()) {
    int u = to_explore.top();
    to_explore.pop();
    res[u] = 'B';
    for (int &v : adj_list[u]) {
      if (vis[v]) continue;
      if (v == n-1) continue;
      vis[v] = 1;
      to_explore.push(v);
    }
  }
  
  cout << res << "\n";
  
  return 0;
}
