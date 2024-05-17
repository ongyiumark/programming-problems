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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int w, h; cin >> h >> w;
  char grid[w][h];
  bool vis[w][h];
  int dist[w][h];
  memset(vis, 0, sizeof vis);
  memset(dist, 0, sizeof dist);

  int si, sj;
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == 'S') {
        si = i;
        sj = j;
      }
    }
  }
  string s; cin >> s;

  int di[] = {-1,1,0,0};
  int dj[] = {0,0,-1,1};
  queue<pii> q;
  q.push({si,sj});
  vis[si][sj] = 1;
  int currNodes = 1;
  int nextNodes = 0;
  int moves = 0;
  while(!q.empty()) {
    auto [i,j] = q.front();
    q.pop();
    dist[i][j] = moves;
    for (int k = 0; k < 4; k++) {
      int x = i+di[k];
      int y = j+dj[k];
      if (x < 0 || x >= w || y < 0 || y >= h) continue;
      if (vis[x][y] || grid[x][y] == '#') continue;
      vis[x][y] = 1;
      q.push({x,y});
      nextNodes++;
    }
    currNodes--;
    if (currNodes == 0) {
      currNodes = nextNodes;
      nextNodes = 0;
      moves++;
    }
  }

  memset(vis, 0, sizeof vis);
  q.push({si,sj});
  vis[si][sj] = 1;
  currNodes = 1;
  nextNodes = 0;
  int idx = 0;
  map<char, int> dir = {{'N', 0}, {'S', 1}, {'W', 2}, {'E', 3} };
  char ans[w][h];
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      ans[i][j] = grid[i][j];
    }
  }
  int n = s.size();
  while(!q.empty()) {
    auto [i,j] = q.front();
    q.pop();
    if (idx == n) {
      if (dist[i][j] == n) ans[i][j] = '!';
      continue;
    }
    char c = s[idx];
    for (int k = 0; k < 4; k++) {
      int x = i+di[k];
      int y = j+dj[k];
      if (dir[c] == k) continue;
      if (x < 0 || x >= w || y < 0 || y >= h) continue;
      if (vis[x][y] || grid[x][y] == '#') continue;
      vis[x][y] = 1;
      q.push({x,y});
      nextNodes++;
    }
    currNodes--;
    if (currNodes == 0) {
      currNodes = nextNodes;
      nextNodes = 0;
      idx++;
    }
  }

  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      cout << ans[i][j];
    }
    cout << endl;
  }
  
  
  return 0;
}
