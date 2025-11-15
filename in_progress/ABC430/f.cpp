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
  cin.tie(0)->sync_with_stdio(false);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    string s; cin >> s;
    vector<vector<int>> adj(n);

    for (int i = 0; i < n-1; i++) {
      if (s[i] == 'L') adj[i+1].emplace_back(i);
      else adj[i].emplace_back(i+1);
    }

    vector<int> in_deg(n);
    for (int u = 0; u < n; u++) {
      for (int v : adj[u]) {
        in_deg[v]++;
      }
    }
    
    vector<int> parents(n), children(n);
    function<void(int,int)> dfs = [&](int u, int p) {
      if (p != -1) parents[u] += parents[p]+1;
      for (int &v : adj[u]) {
        dfs(v, u);
        children[u] += children[v]+1;
      }
    };

    for (int u = 0; u < n; u++) {
      if (in_deg[u] == 0) {
        dfs(u, -1);
      }
    }

    vector<int> res(n);
    for (int u = 0; u < n; u++) {
      res[parents[u]] += 1;
      if(children[u] > 0) res[n-children[u]] -= 1;
    }

    for (int i = 1; i < n; i++) {
      res[i] += res[i-1];
    }
    for (int i = 0; i < n; i++) {
      cout << res[i] << (i+1<n ? " " : "\n");
    }
  }
  
  return 0;
}
