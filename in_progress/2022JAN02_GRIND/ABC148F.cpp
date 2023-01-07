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

const int N = 1e5+5;
vi graph[N];
int vis[N], du[N], dv[N];
int n, u, v;

void dfs(int x, int *d) {
  vis[x] = 1;
  for (int y : graph[x]) {
    if (vis[y]) continue;
    d[y] = d[x]+1;
    dfs(y, d);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> u >> v;
  for (int i = 0; i < n-1; i++) {
    int a, b; cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  memset(vis, 0, sizeof vis);
  memset(du, 0, sizeof du);
  dfs(u, du);

  memset(vis, 0, sizeof vis);
  memset(dv, 0, sizeof dv);
  dfs(v, dv);

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (du[i] < dv[i]) ans = max(ans, dv[i]); 
  }
  cout << ans-1 << "\n";
  
  return 0;
}
