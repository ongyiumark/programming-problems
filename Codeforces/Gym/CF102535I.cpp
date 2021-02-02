/*
  Just do BFS.
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

const int N = 1000;
char grid[N][N];
int vis[N][N];
pair<pii,char> par[N][N];
int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
string moves = "ABCDEFGH";

string bfs(int si, int sj, int ti, int tj, int r, int c){
  memset(vis, 0, sizeof vis);
  queue<pii> q;
  q.push({si,sj});
  vis[si][sj] = 1;
  par[si][sj] = {{-1,-1}, 'X'};
  while(!q.empty()){
    int ui = q.front().first;
    int uj = q.front().second;
    q.pop();
    for (int i = 0; i < 8; i++){
      int vi = ui+dx[i];
      int vj = uj+dy[i];
      if (vi < 0 || vi >= r || vj < 0 || vj >= c) continue;
      if (vis[vi][vj] || grid[vi][vj] == 'X') continue;
      vis[vi][vj] = 1;
      q.push({vi, vj});
      par[vi][vj] = {{ui, uj}, moves[i]};
    }
  }

  if (!vis[ti][tj]) return "Neigh";

  string path;
  while(par[ti][tj].second != 'X'){
    path.append(1, par[ti][tj].second);
    int i = par[ti][tj].first.first;
    int j = par[ti][tj].first.second;
    ti = i;
    tj = j;
  }
  reverse(path.begin(), path.end());
  return "Whinny\n" + path;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--){
    int r, c; cin >> r >> c;
    int si, sj, ti, tj;
    for (int i = 0; i < r; i++){
      for (int j = 0; j < c; j++){
        cin >> grid[i][j];
        if (grid[i][j] == 'K'){
          si = i;
          sj = j;
        }
        if (grid[i][j] == 'F'){
          ti = i;
          tj = j;
        }
      }
    }
    cout << bfs(si, sj, ti, tj, r, c) << endl;
  }
  return 0;
}
