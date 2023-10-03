#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll h, w; cin >> h >> w;
  vector<vector<char>> grid(h, vector<char>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> grid[i][j];
    }
  }

  // transpose
  vector<vector<char>> ngrid;
  bool swapped = false;
  if (h > w) {
    swap(h, w);
    swapped = true;
  }

  ngrid.resize(h);
  for (int i = 0; i < h; i++) {
    ngrid[i].resize(w);
    for (int j = 0; j < w; j++) {
      ngrid[i][j] = (swapped ? grid[j][i] : grid[i][j]);
    }
  }

  string ref = "WALDO";
  vector<vector<vector<int>>> next_ch(h, vector<vector<int>>(w, vector<int>(5)));
  for (int i = 0; i < h; i++) {
    vector<int> last(5, INF);
    for (int j = w-1; j >= 0; j--) {
      for (int k = 0; k < 5; k++) {
        next_ch[i][j][k] = (ref[k] == ngrid[i][j] ? j : INF);
        if (j < w-1) next_ch[i][j][k] = min(next_ch[i][j][k], next_ch[i][j+1][k]);
      }
    }
  }

  int ans = INF;
  for (int ci = 0; ci < h; ci++) {
    for (int cj = 0; cj < w; cj++) {
      vector<int> lo(5, INF);
      for (int ii = 1; ii+ci <= h; ii++) { // height of rectangle
        int hi = 0;
        for (int k = 0; k < 5; k++) {
          lo[k] = min(lo[k], next_ch[ci+ii-1][cj][k]);
          hi = max(hi, lo[k]);
        }
        if (hi < INF) ans = min(ans, (hi-cj+1)*ii);
      }
    }
  }
  if (ans == INF) cout << "impossible\n";
  else cout << ans << "\n";


  return 0;
}