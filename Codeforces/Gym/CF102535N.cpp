/*
  This is just 01BFS in 3D.
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

const int N = 100;
char grid[N][N][N];
bool vis[N][N][N];
int r[N], c[N];

struct coords{
  int k, i, j;
};
vector<coords> stairs[52];

int convert_stairs(char c){
  if (!(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))) return -1;
  if ('A' <= c && c <= 'Z') return c-'A';
  return c-'a'+26;
}

int bfs(int si, int sj, int goal){
  memset(vis, 0, sizeof vis);
  deque<coords> q;
  q.push_back({0, si, sj});
  vis[0][si][sj] = 1;

  int curr_layers = 1;
  int next_layers = 0;
  int moves = 0;
  while(!q.empty()){
    int uk = q.front().k;
    int ui = q.front().i;
    int uj = q.front().j;
    if (uk == goal) return moves;
    q.pop_front();
    for (int di = -1; di <= 1; di++){
      for (int dj = -1; dj <= 1; dj++){
        if (abs(di)+abs(dj) != 1) continue;
        int vi = ui+di;
        int vj = uj+dj;
        if (vi < 0 || vi >= r[uk] || vj < 0 || vj >= c[uk]) continue;
        if (vis[uk][vi][vj]) continue;
        vis[uk][vi][vj] = 1;
        if (grid[uk][vi][vj] == '#') {
          next_layers++;
          q.push_back({uk, vi, vj});
        }
        else{
          curr_layers++;
          q.push_front({uk, vi, vj});
        }
      }
    }

    int st = convert_stairs(grid[uk][ui][uj]);
    if (st != -1){
      for (coords cd : stairs[st]){
        if (vis[cd.k][cd.i][cd.j]) continue;
        vis[cd.k][cd.i][cd.j] = 1;
        curr_layers++;
        q.push_front(cd);
      }
    }
    curr_layers--;
    if (!curr_layers){
      curr_layers = next_layers;
      next_layers = 0;
      moves++;
    }
  }
  return 1e9;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int f; cin >> f;
  for (int k = 0; k < f; k++){
    cin >> r[k] >> c[k];
    for (int i = 0; i < r[k]; i++){
      for (int j = 0; j < c[k]; j++){
        cin >> grid[k][i][j];
        int st = convert_stairs(grid[k][i][j]);
        if (st != -1){
          stairs[st].push_back({k, i, j});
        }
      }
    }
  }

  int ans = 1e9;
  for (int i = 0; i < r[0]; i++){
    for (int j = 0; j < c[0]; j++){
      if (convert_stairs(grid[0][i][j]) == -1) continue;
      ans = min(ans, bfs(i, j, f-1));
    }
  }
  if (ans == 1e9) cout << "DAMN, THE ABSCONDER ABSCONDS AGAIN!" << endl;
  else cout << ans << endl;
  return 0;
}
