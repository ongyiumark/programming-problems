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

const int N = 1e4;
const int INF = 1e5;
bool vis[N];
set<int> graph[N];

int bfs(int s, int t) {
  memset(vis, 0, sizeof vis);
  queue<int> q;
  q.push(s);
  vis[s] = 1;

  int currNodes = 1;
  int nextNodes = 0;
  int moves = 0;
  while(!q.empty()) {
    int u = q.front();
    if (u == t) return moves;
    q.pop();
    for (int v : graph[u]) {
      if (vis[v]) continue;
      vis[v] = 1;
      nextNodes++;
      q.push(v);
    }
    currNodes--;
    if (!currNodes) {
      currNodes = nextNodes;
      nextNodes = 0;
      moves++;
    }
  }
  return 1e5;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int h, w; cin >> h >> w;
  int grid[h][w];
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> grid[i][j];
    }
  }

  int bot = 0;
  set<int> tops;
  for (int j = 0; j < w; j++) {
    tops.insert(grid[0][j]);
    graph[bot].insert(grid[h-1][j]);
  }

  for (int i = 0; i < h-1; i++) {
    for (int j = 0; j < w; j++) {
      if (grid[i][j] == grid[i+1][j]) continue;
      graph[grid[i+1][j]].insert(grid[i][j]);
    }
  } 

  if (tops.size() == 1) {
    int a = *tops.begin();
    cout << bfs(0, a) << endl;
    return 0;
  }

  int a = *tops.begin();
  int b = *++tops.begin();
  
  int ans = bfs(0,a)+bfs(0,b);
  // Brute force all centers
  for (int x = 1; x < N; x++) {
    if (graph[x].size() == 0) continue; 
    int tmp1 = bfs(0,x)+bfs(x,a)+bfs(x,b);
    ans = min(ans, tmp1);
  }
  cout << ans << endl;
  return 0;
}
