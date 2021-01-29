/*
  There shouldn't be any black cell that's completely surrounded by white.
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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int h, w; cin >> h >> w;
  char grid[h][w];
  int cnt[h][w];
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      cin >> grid[i][j];
    }
  }
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      if (grid[i][j] == '.') continue;
      for (int di = -1; di <= 1; di++){
        for (int dj = -1; dj <= 1; dj++){
          if (abs(di)+abs(dj) != 1) continue;
          int x = i + di;
          int y = j + dj;
          if (x < 0 || x >= h || y < 0 || y >= w) continue;
          cnt[x][y]++;
        }
      }
    }
  }


  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      if (grid[i][j] == '#' && cnt[i][j] == 0){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
