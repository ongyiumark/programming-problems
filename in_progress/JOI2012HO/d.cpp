/*
  Do prefix sums in different directions until you get your desired output.
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

const int N  = 5e3+5;
int grid[N][N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m; cin >> n >> m;
  memset(grid, 0, sizeof grid);
  for (int i = 0; i < m; i++){
    int a, b, x; cin >> a >> b >> x;
    a--;
    b--;
    grid[a][b]++;
    grid[a][b+1]--;
    grid[a+x+1][b]--;
    grid[a+x+1][b+x+2]++;
    grid[a+x+2][b+1]++;
    grid[a+x+2][b+x+2]--;
  }

  // diagonal
  for (int i = 1; i < n; i++){
    for(int j = 1; j < n; j++){
      grid[i][j] += grid[i-1][j-1];
    }
  }

  //top to down
  for (int j = 0; j < n; j++){
    for (int i = 1; i < n; i++){
      grid[i][j] += grid[i-1][j];
    }
  }

  //left to right;
  for (int i = 0; i < n; i++){
    for (int j = 1; j < n; j++){
      grid[i][j] += grid[i][j-1];
    }
  }

  int cnt = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j <= i; j++){
      cnt += grid[i][j] > 0;
    }
  }
  cout << cnt << endl;
  return 0;
}
