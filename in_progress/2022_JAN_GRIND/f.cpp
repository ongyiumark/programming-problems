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
vector<int> graph[N][26];
vector<tuple<int,int,char>> edges;
bool vis[N][N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    char c;
    cin >> a >> b >> c;
    edges.push_back({a,b,c});
    edges.push_back({b,a,c});
    graph[a][c-'a'].push_back(2*i);
    graph[b][c-'a'].push_back(2*i+1);
  }
  memset(vis, 0, sizeof vis);


  queue<tuple<int,int>> q;
  q.push({m+1, m+1});
  int curr_nodes = 1;
  int next_layer = 0;
  int moves = 0;
  int found = 0;

  while(!q.empty()) {
    auto [j, k] = q.front();
    int u, v;
    if (j == k && j == m+1) {
      u = 1;
      v = n;
    }
    else {
      u = get<1>(edges[j]);
      v = get<1>(edges[k]);
    }

    q.pop();

    if (u == v) found = 1;
    if (found) break;
    for (int i = 0; i < 26; i++) {
      for (int idx : graph[u][i]) {
        auto [a,b,c] = edges[idx];
        if (b == v) found = 2;
      }
    }
    if (found) break;
    for (int i = 0; i < 26; i++) {
      for (auto j : graph[u][i]) {
        for (auto k : graph[v][i]) {
          if (vis[j][k]) continue;
          q.push({j,k});
          vis[j][k] = 1;
          next_layer++;
        }
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
