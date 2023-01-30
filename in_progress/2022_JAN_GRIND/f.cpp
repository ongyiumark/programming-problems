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

const int N = 1e3+5;
vector<pair<int, char>> graph[N];
bool vis[N][N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    char c;
    cin >> a >> b >> c;
    graph[a].push_back({b,c});
    graph[b].push_back({a,c});
  }

  memset(vis, 0, sizeof vis);

  queue<ii> q;
  q.push({1,n});
  int curr_nodes = 1;
  int next_layer = 0;
  int moves = 0;
  int found = 0;

  while(!q.empty()) {
    auto [u,v] = q.front();
    q.pop();

    if (u == v) found = 1;
    if (found) break;
    for (auto [uu,cu] : graph[u]) {
      if (uu == v) found = 2;
    }
    if (found) break;

    for (auto [uu,cu] : graph[u]) {
      for (auto [vv,cv] : graph[v]) {
        int x = min(uu,vv);
        int y = max(uu,vv);

        if (vis[x][y]) continue;
        if (cu != cv) continue;
        q.push({x,y});
        vis[x][y] = 1;
        next_layer++;
      }
    }

    curr_nodes--;
    if (curr_nodes == 0) {
      curr_nodes = next_layer;
      next_layer = 0;
      moves++;
    }
  }

  if (!found) cout << -1 << "\n";
  else if (found == 1) cout << 2*moves << "\n";
  else cout << 2*moves + 1 << "\n";
  
  return 0;
}
