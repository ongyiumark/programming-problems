/*
  Just keep track of which rows and columns to delete.
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
bool grid[N][N];
bool row[N], col[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int h, w; cin >> h >> w;
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      char c; cin >> c;
      grid[i][j] = (c == '#');
    }
  }
  for (int i = 0; i < h; i++){
    bool rem = 1;
    for (int j = 0; j < w; j++){
      rem &= (!grid[i][j]);
    }
    row[i] = rem;
  }

  for (int j = 0; j < w; j++){
    bool rem = 1;
    for (int i = 0; i < h; i++){
      rem &= (!grid[i][j]);
    }
    col[j] = rem;
  }

  for (int i = 0; i < h; i++){
    if (row[i]) continue;
    for (int j = 0; j < w; j++){
      if (col[j]) continue;
      cout << (grid[i][j] ? '#' : '.');
    }
    cout << endl;
  }
  return 0;
}
