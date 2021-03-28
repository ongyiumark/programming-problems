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

int r, c;
const int N = 300;
int grid[N][N];
int ngrid[N][N];

int di[] = {-1,1, 0,0};
int dj[] = {0,0, -1,1};
void bfs(int i, int j){
  queue<pair<int,int>> q;
  q.push({i, j});
  while(!q.empty()){
    int ci = q.front().first;
    int cj = q.front().second;
    q.pop();
    for (int d = 0; d < 4; d++){
      int x = ci+di[d];
      int y = cj+dj[d];
      if (x < 0 || x >= r || y < 0 || y >= c) continue;
      ngrid[x][y] = max(ngrid[x][y], ngrid[ci][cj]-1);
    }
  }
}

void testcase(){
  cin >> r >> c;
  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){
      cin >> grid[i][j];
      ngrid[i][j] = grid[i][j];
    }
  }
  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){
      bfs(i, j);
    }
  }
  ll ans = 0;
  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){
      ans += ngrid[i][j]-grid[i][j];
    }
  }
  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  for (int x = 1; x <= t; x++){
    cout << "Case #" << x << ": ";
    testcase(); 
  }
  return 0;
}
