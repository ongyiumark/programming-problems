/*
  Try all possible perm(c,3) possibilities.
  The naive solution would be too slow.

  We can speed it up by precomputing the cost when (i+j)%3 = 0,1,2 is painted k.
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

bool vis[30];
int D[30][30], grid[500][500], cost[3][30];
int n;
int ans = 1e9;
vector<int> cols;

int solve(){
  int ret = 0;
  for (int i = 0; i < 3; i++){
    ret += cost[i][cols[i]];
  }
  return ret;
}

void choose3(int c, int i){
  if (i >= 3){
    ans = min(ans, solve());
    return;
  }
  for (int j = 0; j < c; j++){
    if (vis[j]) continue;
    vis[j] = 1;
    cols.push_back(j);
    choose3(c, i+1);
    cols.pop_back();
    vis[j] = 0;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int c; cin >> n >> c;
  for (int i = 0; i < c; i++){
    for (int j = 0; j < c; j++){
      cin >> D[i][j];
    }
  }

  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> grid[i][j];
      grid[i][j]--;
    }
  }

  memset(cost, 0, sizeof cost);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      for (int k = 0; k < c; k++){
        cost[(i+j)%3][k] += D[grid[i][j]][k];
      }
    }
  }
  memset(vis, 0, sizeof vis);
  choose3(c, 0);

  cout << ans << endl;
  return 0;
}
