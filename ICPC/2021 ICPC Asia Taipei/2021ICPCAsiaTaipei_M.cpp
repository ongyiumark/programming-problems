#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int di[] = {-1,0,1,0};
int dj[] = {0,1,0,-1};
int main() {
  cin.tie(0)->sync_with_stdio(0);

  int m, n; cin >> m >> n;
  vector grid(m+2, vector(n+2, 0));
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> grid[i][j];
    }
  }
  int s, f, r; cin >> s >> f >> r;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (grid[i][j] != s) continue;
      for (int k = 0; k < 4; k++) {
        int xf = i+di[k], yf = j+dj[k];
        int xr = i+di[(k+1)%4], yr = j+dj[(k+1)%4];
        if (grid[xf][yf] == f && grid[xr][yr] == r) {
          cout << i-1 << " " << j-1 << "\n";
          break;
        }
      }
    }
  }

  return 0;
}