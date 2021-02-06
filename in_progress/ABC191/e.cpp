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

const int N = 2000;
ll adjmat[N][N];
int vis[N];
int n;

ll memo[N];
ll dfs(int u, int s){
  if (vis[u] == 1) {
    if (u != s) return 1e9;
    else return 0;
  }
  if (vis[u] == 2) return memo[u];
  vis[u] = 1;
  ll ret = 1e18;
  for (int v = 0; v < n; v++){
    if (adjmat[u][v] > 1e9) continue;
    ret = min(dfs(v,s)+adjmat[u][v], ret);
  }
  vis[u] = 2;
  return memo[u] = ret;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  memset(adjmat, 15, sizeof adjmat);
  int m; cin >> n >> m;
  for (int i = 0; i < m; i++){
    ll a, b, c; cin >> a >> b >> c;
    a--; b--;
    adjmat[a][b] = min(adjmat[a][b], c);
  }

  for (int i = 0; i < n; i++){
    memset(memo, -1, sizeof memo);
    memset(vis, 0, sizeof vis);
    ll ans = dfs(i,i);
    if (ans > 1e9) ans = -1;
    cout << ans << endl;
  }
  return 0;
}
