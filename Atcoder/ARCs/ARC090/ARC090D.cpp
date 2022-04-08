/*
  First thing to notice is that if its a valid information base, then 0 to 10^9 is enough.
    So, we don't need to worry about exceeding 10^9.

  Then, the answer is to topologically sort the graph and greedily assign the positions.
    If there's no valid topological sorting, i.e., a cycle exists, then "No".
    If conflicts occur while assigning positions, then "No".
  Otherwise, "Yes."
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

const int N = 1e5+5;
vector<pii> reqs[N];
int vis[N];
int pos[N];
vector<int> toposort;

bool dfs(int u) {
  vis[u] = 1;
  bool valid = true;
  for (auto [l,d] : reqs[u]){
    if (vis[l] == 2) continue;
    if (vis[l] == 1) return false;
    valid &= dfs(l);
  }
  vis[u] = 2;
  toposort.push_back(u);
  return valid;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  memset(pos, -1, sizeof pos);
  memset(vis, 0, sizeof vis);
  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int l, r, d; cin >> l >> r >> d;
    reqs[r].push_back({l,d});
  }
  
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    if (!dfs(i)) {
      cout << "No" << endl;
      return 0;
    }
  }

  for (int i = 0; i < n; i++) {
    int u = toposort[i];
    if (reqs[u].size() == 0) pos[u] = 0;
    for (auto [l,d] : reqs[u]) {
      if (pos[u] == -1) pos[u] = pos[l]+d;
      else if (pos[u] != pos[l]+d) {
        cout << "No" << endl;
        return 0;
      }
    }
  }

  cout << "Yes" << endl;
  return 0;
}
