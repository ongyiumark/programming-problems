/*
  This is just BFS with an extra state of how many Star MarKorines has been eaten.
  Since r,c <= 600, the highest number of Star MarKorines eaten that makes sense is 9.
    This is because anything higher will always go out of bounds.
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

vector<vector<char>> grid;
vector<vector<bool>> vis[10];
int r, c;
int dx[] = {-2,-2,-1,-1,1,1,2,2};
int dy[] = {-1,1,-2,2,-2,2,-1,1};

void bfs(int si, int sj, int ti, int tj){
  for (int k = 0; k < 10; k++){
    for (int i = 0; i < r; i++){
      for (int j = 0; j < c; j++){
        vis[k][i][j] = 0;
      }
    }
  }
  queue<piii> q;
  q.push({0,{si, sj}});
  int curr_nodes = 1;
  int next_nodes = 0;
  int moves = 0;
  while(!q.empty()){
    int cmult = q.front().first;
    int ci = q.front().second.first;
    int cj = q.front().second.second;
    q.pop();
    if (ci == ti && cj == tj){
      cout << moves << "\n";
      return;
    }
    for (int k = cmult; k < 10; k++){
      for (int i = 0; i < 8; i++){
        ll mult = (1<<k);
        ll x = ci + dx[i]*mult;
        ll y = cj + dy[i]*mult;
        if (x < 0 || x >= r || y < 0 || y >= c) continue;
        if (vis[k][x][y]) continue;
        if (grid[x][y] == 'O') continue;
        vis[k][x][y] = 1;
        q.push({k,{x,y}});
        next_nodes++;
      }
    }
    curr_nodes--;
    if (!curr_nodes){
      curr_nodes = next_nodes;
      next_nodes = 0;
      moves++;
    }
  }
  cout << "CAN'T CUT THE BLOCK OF CHEESE!" << "\n";
}

void solve(){
  cin >> r >> c;
  grid.resize(r);
  for (int k = 0; k < 10; k++) vis[k].resize(r);
  for (int i = 0; i < r; i++){
    grid[i].resize(c);
    for (int k = 0; k < 10; k++) vis[k][i].resize(c);
    for (int j = 0; j < c; j++){
      cin >> grid[i][j];
    }
  }
  int q; cin >> q;
  while(q--){
    int si, sj, ti, tj;
    cin >> si >> sj >> ti >> tj;
    si--; sj--; ti--; tj--;
    bfs(si, sj, ti, tj);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int b; cin >> b;
  while(b--){
    solve();
  }
  return 0;
}
