/* 
  First idea was dijkstra, but be careful with dealing with ties.
  Make sure to include the number of doors in the state.

  Since the weights of the edges are small, we can use a generalized 01BFS using multiple queues.
  Make sure to include the number of doors in the visited array.
    This particular bug took me forever to fix.
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

struct node{
  int i, j, d; 
};

vector<vector<char>> grid;
vector<vector<vector<bool>>> vis;
int r, c, k;
int bfs(int si, int sj, int ti, int tj){
  queue<node> q[4];
  q[0].push({si, sj, 0});

  for (int moves=0, cnt = 0; cnt < 10; moves++, cnt++){
    while(!q[0].empty()){
      cnt = 0;
      node u = q[0].front();
      if (u.i == ti && u.j == tj) return moves;
      q[0].pop();

      for (int di = -1; di <= 1; di++){
        for (int dj = -1; dj <= 1; dj++){
          if (abs(di)+abs(dj) != 1) continue;
          int x = u.i+di;
          int y = u.j+dj;
          if (x < 0 || x >= r || y < 0 || y >= c) continue;
          if (grid[x][y] == '#') continue;
          if (grid[x][y] == '.'){
            if (vis[x][y][u.d]) continue;
            vis[x][y][u.d] = 1;
            q[1].push({x,y,u.d});
          }
          if (grid[x][y] == 'D'){
            if (k == 1 && grid[u.i][u.j] == 'D') continue;
            int w = (u.d == k ? 3 : 2);
            if (vis[x][y][min(k,u.d+1)]) continue;
            vis[x][y][min(k,u.d+1)] = 1;
            q[w].push({x,y,min(k,u.d+1)});
          }
        }
      }
    }

    for (int i = 0; i < 3; i++){
      swap(q[i], q[i+1]);
    }
  }
  return -1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--){
    cin >> r >> c >> k;
    grid.resize(r);
    vis.resize(r);
    int si, sj, ti, tj;
    for (int i = 0; i < r; i++){
      grid[i].resize(c);
      vis[i].resize(c);
      for (int j = 0; j < c; j++){
        cin >> grid[i][j];
        if (grid[i][j] == 'A') {
          si = i, sj = j;
          grid[i][j] = '.';
        }
        if (grid[i][j] == 'B') {
          ti = i, tj = j;
          grid[i][j] = '.';
        }

        vis[i][j].resize(k+1);
        for (int x = 0; x <= k; x++) vis[i][j][x] = 0;
      }
    }

    int moves = bfs(si, sj, ti, tj);
    if (moves == -1) cout << "HAHAHUHU";
    else cout << moves;
    cout << endl;
  }
  return 0;
}