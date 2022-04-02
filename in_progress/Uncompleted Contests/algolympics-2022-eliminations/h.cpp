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

int n, m;
int shield[505];
vector<vector<int>> graph;
bool vis[505];

bool dfs(int u, int x) {
  bool ans = false;
  if (u == n-1) return true;
  for (int v : graph[u]) {
    if (vis[v]) continue;
    if (shield[v] >= x) {
      vis[v] = 1;
      ans |= dfs(v, x);
    }
  }
  return ans;
}

bool valid(int x) {
  memset(vis, 0, sizeof vis);
  vis[0] = 1;
  if (shield[0] < x) return false;
  if (shield[n-1] < x) return false;
  return dfs(0, x);
}

void testcase(){
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> shield[i];
  }
  graph.resize(n);
  for (int i = 0; i < n; i++) graph[i] = vector<int>();
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    u--; v--;
    graph[u].push_back(v);
  }

  int lo = 1;
  int hi = min(shield[0], shield[n-1]);
  int ans = -1;
  while(lo <= hi) {
    int mid = hi - (hi-lo)/2;
    if (valid(mid)) {
      ans = mid;
      lo = mid+1;
    }
    else hi = mid-1;
  }
  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T; cin >> T;
  for (int i = 0; i < T; i++) {
    testcase();
  }
  return 0;
}
