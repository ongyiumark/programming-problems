/*
  Normal BFS. Just make sure to handle teleportation properly.
*/

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

const int N = 2e3+5;
bool vis[N][N];
char grid[N][N];
vector<ii> porters[26];
bool ported[26];

int dist[N][N];

int di[] = {0, 0, -1, 1};
int dj[] = {-1, 1, 0, 0};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int h, w; cin >> h >> w;
  ii s, g;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> grid[i][j];
      vis[i][j] = 0;
      dist[i][j] = -1;

      if ('a' <= grid[i][j] && grid[i][j] <= 'z') {
        porters[grid[i][j]-'a'].push_back({i,j});
      }
      else if (grid[i][j] == 'S') {
        s = {i,j};
      }
      else if (grid[i][j] == 'G') {
        g = {i,j};
      }
    }
  }

  memset(ported, 0, sizeof ported);

  queue<ii> q;
  q.push(s);
  dist[s.first][s.second] = 0;
  vis[s.first][s.second] = 1;
  while(!q.empty()) {
    auto [ci, cj] = q.front();
    q.pop();

    for (int d = 0; d < 4; d++) {
      int x = ci+di[d];
      int y = cj+dj[d];
      if (x < 0 || x >= h || y < 0 || y >= w) continue;
      if (vis[x][y]) continue;
      if (grid[x][y] == '#') continue;

      vis[x][y] = 1;
      q.push({x,y});
      dist[x][y] = dist[ci][cj]+1;
    }

    if ('a' <= grid[ci][cj] && grid[ci][cj] <= 'z') {
      if (!ported[grid[ci][cj]-'a']) {
        for (ii t : porters[grid[ci][cj]-'a']) {
          if (vis[t.first][t.second]) continue;
          vis[t.first][t.second] = 1;
          q.push(t);
          dist[t.first][t.second] = dist[ci][cj]+1;
        }
        ported[grid[ci][cj]-'a'] = 1;
      }
    }
  }

  cout << dist[g.first][g.second] << "\n";
  return 0;
}
