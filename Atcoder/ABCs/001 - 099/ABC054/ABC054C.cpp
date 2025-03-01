/*
  DP on graphs.
  dp[i][vis] where i is the current node and vis is the bitmask.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector<int> graph[8];
int n;
int dp[8][256];
int solve(int i, int vis){
  int& ret = dp[i][vis];
  if (ret != -1) return ret;
  if (vis == ((1<<n)-1)) return ret = 1;

  ret = 0;
  for (int v : graph[i]){
    if ((1<<v)&vis) continue;
    ret += solve(v, (1<<v)|vis);
  }
  return ret;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(dp, -1, sizeof dp);
  int m; cin >> n >> m;
  for (int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    a--; b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  cout << solve(0, 1) << endl;
  return 0;
}
