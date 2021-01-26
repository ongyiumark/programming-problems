/*
  To maximize the score, we turn everything black except for the shortest path.
  We can compute for the length of the shortest path with BFS.

  The answer is H*W - length_of_path - number_of_black_cells.
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

const int N = 50;
bool grid[N][N];
bool vis[N][N];
int h, w;

int bfs(pii s){
  queue<pii> q;
  q.push(s);
  vis[s.first][s.second] = 1;
  int curr_layers = 1;
  int next_layers = 0;
  int moves = 1;
  while(!q.empty()){
    int ui = q.front().first;
    int uj = q.front().second;
    q.pop();
    if (ui == h-1 && uj == w-1){
      return moves;
    }
    for (int di = -1; di <= 1; di++){
      for (int dj = -1; dj <= 1; dj++){
        if (abs(di)+abs(dj) > 1) continue;
        int vi = ui + di;
        int vj = uj + dj;
        if (vi < 0 || vi >= h || vj < 0 || vj >= w) continue;
        if (grid[vi][vj] || vis[vi][vj]) continue;
        vis[vi][vj] = 1;
        q.push({vi, vj});
        next_layers++;
      }
    }

    curr_layers--;
    if (!curr_layers){
      curr_layers = next_layers;
      next_layers = 0;
      moves++;
    }
  }
  return -1;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> h >> w;
  int bcnt = 0;
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      char c; cin >> c;
      grid[i][j] = (c == '#');
      bcnt += grid[i][j];
    }
  }

  memset(vis, 0, sizeof vis);
  if (grid[0][0]) {
    cout << -1 << endl;
    return 0;
  }
  
  int path = bfs({0,0});
  if (path == -1) cout << -1 << endl;
  else cout << h*w-path-bcnt << endl;
  return 0;
}
