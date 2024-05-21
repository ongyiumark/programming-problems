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

const int INF = 1e9;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, m; cin >> n >> m;
  vector<vector<int>> adj(3*n);
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    u--; v--;
    adj[u].push_back(v+n);
    adj[u+n].push_back(v+2*n);
    adj[u+2*n].push_back(v);
  }

  int s, t; cin >> s >> t;
  s--; t--;
  queue<int> q;
  q.push(s);
  vector<int> d(3*n, INF);
  d[s] = 0;
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : adj[u]) {
      if (d[v] < INF) continue;
      d[v] = d[u]+1;
      q.push(v);
    }
  }
  cout << (d[t] < INF ? d[t]/3 : -1) << "\n";
  return 0;
}
