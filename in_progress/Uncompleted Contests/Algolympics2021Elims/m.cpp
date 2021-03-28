/*
  BFS from the starting point and BFS from the m-th move.
  Get the cells that are n moves from the starting point and n-m moves from the m-th move.
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
vector<vector<bool>> vis[10], nvis[10];
vector<vector<int>> viscnt;
int r, c, n, m;
int dx[] = {-2,-2,-1,-1,1,1,2,2};
int dy[] = {-1,1,-2,2,-2,2,-1,1};

const int N = 1e5+1;
int Mx[N], My[N];

int logi(int x){
  int cnt = 0;
  while(x > 1){
    cnt++;
    x /= 2;
  }
  return cnt;
}

void bfs(int si, int sj){
  for (int k = 0; k < 10; k++){
    for (int i = 0; i < r; i++){
      for (int j = 0; j < c; j++){
        vis[k][i][j] = 0;
        nvis[k][i][j] = 0;
      }
    }
  }
  queue<piii> q;
  q.push({0,{si, sj}});
  vis[0][si][sj] = nvis[0][si][sj] = 1;
  viscnt[si][sj]++;
  int curr_nodes = 1;
  int next_nodes = 0;
  int moves = 0;
  while(!q.empty()){
    if (moves == n) break;
    int cmult = q.front().first;
    int ci = q.front().second.first;
    int cj = q.front().second.second;
    viscnt[ci][cj]++;
    q.pop();
    for (int k = cmult; k < 15; k++){
      for (int i = 0; i < 8; i++){
        ll mult = (1<<k);
        ll x = ci + dx[i]*mult;
        ll y = cj + dy[i]*mult;
        if (x < 0 || x >= r || y < 0 || y >= c) continue;
        if (vis[k][x][y]) continue;
        if (grid[x][y] == 'O') continue;
        if (moves < m) nvis[k][x][y] = 1;
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
      if (moves == n) break;
    }
  }
  
  while(!q.empty()){
    q.pop();
  }

  q.push({logi(min(abs(Mx[m]-Mx[m-1]), abs(My[m]-My[m-1]))),{Mx[m], My[m]}});
  curr_nodes = 1;
  next_nodes = 0;
  moves = m;
  while(!q.empty()){
    if (moves == n) break;
    int cmult = q.front().first;
    int ci = q.front().second.first;
    int cj = q.front().second.second;
    viscnt[ci][cj]++;
    q.pop();
    for (int k = cmult; k < 15; k++){
      for (int i = 0; i < 8; i++){
        ll mult = (1<<k);
        ll x = ci + dx[i]*mult;
        ll y = cj + dy[i]*mult;
        if (x < 0 || x >= r || y < 0 || y >= c) continue;
        if (nvis[k][x][y]) continue;
        if (grid[x][y] == 'O') continue;
        nvis[k][x][y] = 1;
        q.push({k,{x,y}});
        next_nodes++;
      }
    }
    curr_nodes--;
    if (!curr_nodes){
      curr_nodes = next_nodes;
      next_nodes = 0;
      moves++;
      if (moves == n) break;
    }
  }

  set<pii> ans;
  while(!q.empty()){
    int cmult = q.front().first;
    int ci = q.front().second.first;
    int cj = q.front().second.second;
    q.pop();
    if (viscnt[ci][cj] == 0) {
      ans.insert({ci,cj});
    }
  }

  cout << ans.size() << "\n";
  for (auto p : ans){
    cout << p.first+1 << " " << p.second+1 << "\n";
  }
}

void solve(){
  cin >> r >> c >> m >> n;
  grid.resize(r);
  viscnt.resize(r);
  for (int k = 0; k < 10; k++) {
    vis[k].resize(r);
    nvis[k].resize(r);
  }
  for (int i = 0; i < r; i++){
    grid[i].resize(c);
    viscnt[i].resize(c);
    for (int k = 0; k < 10; k++) {
      vis[k][i].resize(c);
      nvis[k][i].resize(c);
    }
    for (int j = 0; j < c; j++){
      cin >> grid[i][j];
      viscnt[i][j] = 0;
    }
  }
  for (int i = 0; i <= m; i++){
    cin >> Mx[i] >> My[i];
    Mx[i]--; My[i]--;
  }

  bfs(Mx[0], My[0]);
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
