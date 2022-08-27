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

vector<int> di = {1,1,-1,-1,2,2,-2,-2};
vector<int> dj = {2,-2,2,-2,1,-1,1,-1};
int si, sj, ti, tj;

const int N = 750+5;
bool vis[N][N];
bool isknight[N][N];
bool found = false, change = true;
vector<vector<int>> notsafe(N, vector<int>(N,0)); 
int r, c; 

void bfs(int si, int sj) {
  queue<pii> q;
  q.push({si,sj});
  vis[si][sj] = 1;
  while (!q.empty()) {
    auto [i,j] = q.front();
    q.pop();
    //cout << i << " " << j << endl;
    if (i == ti && j == tj) found = true;
    if (isknight[i][j]) {
      isknight[i][j] = 0;
      for (int k = 0; k < 8; k++) {
        int x = i+di[k];
        int y = j+dj[k];
        if (x < 0 || x >= r || y < 0 || y >= c) continue;
        notsafe[x][y]--;
        if (notsafe[x][y] == 0) {
          bool can_visit = 0;
          for (int ni = 0; ni < r; ni++) {
            int tmpx = x-ni;
            if (tmpx < 0) break; 
            if (notsafe[tmpx][y]) {
              if (isknight[tmpx][y]) break;
              continue;
            }
            can_visit |= vis[tmpx][y];
            if (isknight[tmpx][y]) break;
          }
          for (int ni = 0; ni < r; ni++) {
            int tmpx = x+ni;
            if (tmpx >= r) break; 
            if (notsafe[tmpx][y]) {
              if (isknight[tmpx][y]) break;
              continue;
            }
            can_visit |= vis[tmpx][y];
            if (isknight[tmpx][y]) break;
          }
          for (int nj = 0; nj < c; nj++) {
            int tmpy = y-nj;
            if (tmpy < 0) break;
            if (notsafe[x][tmpy]) {
              if (isknight[x][tmpy]) break;
              continue;
            }
            can_visit |= vis[x][tmpy];
            if (isknight[x][tmpy]) break;
          }
          for (int nj = 0; nj < c; nj++) {
            int tmpy = y+nj;
            if (tmpy >= c) break;
            if (notsafe[x][tmpy]) {
              if (isknight[x][tmpy]) break;
              continue;
            }
            can_visit |= vis[x][tmpy];
            if (isknight[x][tmpy]) break;
          }
          if (can_visit) q.push({x,y});
        }
      }
    }

    for (int ni = 0; ni < r; ni++) {
      int x = i-ni;
      if (x < 0 || vis[x][j]) continue;
      if (notsafe[x][j]) {
        if (isknight[x][j]) break;
        continue;
      }
      vis[x][j] = 1;
      q.push({x,j});
      if (isknight[x][j]) break;
    }
    for (int ni = 0; ni < r; ni++) {
      int x = i+ni;
      if (x >= r || vis[x][j]) continue;
      if (notsafe[x][j]) {
        if (isknight[x][j]) break;
        continue;
      }
      vis[x][j] = 1;
      q.push({x,j});
      if (isknight[x][j]) break;
    }
    for (int nj = 0; nj < c; nj++) {
      int y = j-nj;
      if (y < 0 || vis[i][y]) continue;
      if (notsafe[i][y]) {
        if (isknight[i][y]) break;
        continue;
      }
      vis[i][y] = 1;
      q.push({i,y});
      if (isknight[i][y]) break;
    }
    for (int nj = 0; nj < c; nj++) {
      int y = j+nj;
      if (y >= c || vis[i][y]) continue;
      if (notsafe[i][y]) {
        if (isknight[i][y]) break;
        continue;
      }
      vis[i][y] = 1;
      q.push({i,y});
      if (isknight[i][y]) break;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> r >> c;
  vector<vector<char>> grid(r, vector<char>(c));
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == 'R') {
        si = i; sj = j;
      }
      if (grid[i][j] == 'T') {
        ti = i; tj = j;
      }
    }
  } 

  memset(isknight, 0, sizeof isknight);
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (grid[i][j] == 'K') {
        isknight[i][j] = 1;
        for (int k = 0; k < 8; k++) {
          int x = i+di[k];
          int y = j+dj[k];
          if (x < 0 || x >= r || y < 0 || y >= c) continue;
          notsafe[x][y]++;
        }
      }
    }
  }

  memset(vis, 0, sizeof vis);
  bfs(si, sj);
  
  cout << (found ? "yes" : "no") << endl;;


  return 0;
}
