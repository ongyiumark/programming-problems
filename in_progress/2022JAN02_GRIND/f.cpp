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

const int N = 2e5+5;
int p[N];
int vis[N];
int n;
queue<int> q;

int dfs(int u) {
  q.push(u);
  if (vis[p[u]] == -1) return 0;
  if (vis[p[u]] == 0) {
    vis[p[u]] = vis[u]+1;
    return dfs(p[u]);
  }
  else return vis[u];
} 

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 1; i <= n; i++) cin >> p[i];
  for (int i = 1; i <= n; i++) vis[i] = 0;

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i] == -1) continue;
    ans = max(dfs(i), ans);
    while(!q.empty()) {
      vis[q.front()] = -1;
      q.pop();
    }
  }

  if (ans > 0 && ans % 2 == 1) cout << "IMPOSSIBLE\n";
  else cout << "POSSIBLE\n";

  return 0;
}
