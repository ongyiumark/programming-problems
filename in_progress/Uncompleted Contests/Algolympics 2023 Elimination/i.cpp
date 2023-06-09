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

const int N = 2e5+5;
vector<int> graph[N];
vector<int> topo;

bool toposort(int n) {
  vector<int> in_deg(n, 0);

  for (int u = 0; u < n; u++) {
    for (int v : graph[u]) {
      in_deg[v]++;
    }
  }

  priority_queue<int> pq;
  for (int u = 0; u < n; u++) {
    if (in_deg[u] == 0) pq.push(u);
  }


  int count = 0;

  while (!pq.empty()) {
    int u = pq.top();
    pq.pop();

    for (int v : graph[u]) {
      in_deg[v]--;
      if (in_deg[v] == 0) pq.push(v);
    }

    topo.push_back(u+1);

    count++;
  }

  return count == n;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
      graph[i].clear();
    }

    for (int i = 0; i < m; i++) {
      int u, v; cin >> u >> v;
      u--; v--;
      graph[u].push_back(v);
    }

    topo.clear();
    bool val = toposort(n);

    if (!val) {
      cout << "IMPOSSIBLE\n";
    }
    else {
      for (int i = 0; i < n; i++) {
        cout << topo[i];
        if (i+1 < n) cout << " ";
        else cout << "\n";
      }
    }
  }
  
  return 0;
}
