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

const int N = 2e3+100;
bool vis[N][N];

char ngrid[N][N];
int di[] = {-1, 0, 1, 0};
int dj[] = {0, -1, 0, 1};
int n;
int curr;

void floodfill(int i, int j) {
  if (vis[i][j]) return;
  if (ngrid[i][j] != '.') return;
  if (i+1 < n && i > 0 && ngrid[i+1][j]==ngrid[i-1][j] && ngrid[i+1][j] == '|') return;
  if (j < n && j > 0 && ngrid[i][j+1]==ngrid[i][j-1] && ngrid[i][j+1] == '-') return;
  vis[i][j] = 1;

  for (int k = 0; k < 4; k++) {
    int x = i+di[k];
    int y = j+dj[k];
    if (x < 0 || x >= n || y < 0 || y >= n) continue;
    if (vis[x][y]) continue;
    if (ngrid[x][y] != '.') continue;
    if (ngrid[x][y] == '.') {
      if (y+1 < n && y-1 > 0 && ngrid[x][y+1]==ngrid[x][y-1] && ngrid[x][y-1] == '-') continue;
      if (x+1 < n && x-1 > 0 && ngrid[x+1][y]==ngrid[x-1][y] && ngrid[x-1][y] == '|') continue;
    }

    floodfill(x, y);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int r, c; cin >> r >> c;
  char grid[r][c];
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> grid[i][j];
    }
  }
  n = r+c+5;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ngrid[i][j] = '.';
    }
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (grid[i][j] == '/') ngrid[i+j+2][i-j+c+2] = '-';
      if (grid[i][j] == '\\') ngrid[i+j+2][i-j+c+2] = '|';
    }
  }

  memset(vis, 0, sizeof vis);
  curr = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (vis[i][j]) continue;
      if (ngrid[i][j] != '.') continue;
      if (i+1 < n && i > 0 && ngrid[i+1][j]==ngrid[i-1][j] && ngrid[i+1][j] == '|') continue;
      if (j < n && j > 0 && ngrid[i][j+1]==ngrid[i][j-1] && ngrid[i][j+1] == '-') continue;
      ++curr;
      floodfill(i, j);
    }
  }
  
  cout << curr-1 << endl;
  
  return 0;
}
