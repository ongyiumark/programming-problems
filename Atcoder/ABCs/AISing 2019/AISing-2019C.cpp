/*
  Do BFS. Connected blacks have the same number of white pairs.
  BFS from one black and count how many blacks are connected to it.
    Multiply the answer by the number of blacks.
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

const int N = 405;
int h, w;
bool grid[N][N];
bool vis[N][N];
pii moves[4] = {{0,1},{1,0},{-1,0},{0,-1}};

ll bfs(int si, int sj){
  queue<pii> q;
  q.push({si,sj});
  vis[si][sj] = 1;
  ll total, seen;
  total = seen = 0;
  while(!q.empty()){
    int ci = q.front().first;
    int cj = q.front().second;
    if (grid[ci][cj]) seen++;
    else total++;
    
    q.pop();
    
    for (int k = 0; k < 4; k++){
      int di = moves[k].first;
      int dj = moves[k].second;
      int x = ci + di;
      int y = cj + dj;
      if (x < 0 || x >= h) continue;
      if (y < 0 || y >= w) continue;
      if (vis[x][y]) continue;
      if (grid[ci][cj] == grid[x][y]) continue;

      vis[x][y] = 1;
      q.push({x,y});
    } 
  }
  return total*seen;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> h >> w;
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      char c; cin >> c;
      grid[i][j] = (c=='#');
    }
  }

  memset(vis, 0, sizeof vis);

  ll ans = 0;
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      if (vis[i][j]) continue;
      ans += bfs(i, j);
    }
  }
  cout << ans << endl;
  
  return 0;
}
