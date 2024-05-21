/*
  Firstly, we can ignore the lengths. We only care about its parity.
  We DFS from any node and only change color if we pass by an edge with an odd length.
    It can be proved that doing this will satisfy the conditions.
    This is because two odds make an even, two evens make an even, and an odd and an even make an odd.
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
vector<pair<int, bool>> graph[N];
bool vis[N];
bool col[N];

void dfs(int u, int p){
  vis[u] = 1;
  for (auto vv : graph[u]){
    int v = vv.first;
    bool w = vv.second;
    if (vis[v]) continue;
    if (v == p) continue;
    col[v] = col[u]^w;
    dfs(v, u);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  for (int i = 0; i < n; i++){
    int u, v, w; cin >> u >> v >> w;
    w %=2;
    graph[u].push_back({v,w});
    graph[v].push_back({u,w});
  }

  memset(vis, 0, sizeof vis);
  memset(col, 0, sizeof col);
  dfs(1,-1);

  for (int i = 1; i <= n; i++){
    cout << col[i] << endl;
  }

  return 0;
}
