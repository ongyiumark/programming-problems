/*
  Sort of greedy approach.
  If the current node is higher than some of its children, we assign it to the lowest child.
  Then, the value of the current node is now what we assigned it.
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

ll F[N];
ll P[N];
vector<int> graph[N];

ll score[N];
ll lo[N];

void dfs(int u) {
  for (int v : graph[u]) {
    if (v < u) continue;
    dfs(v);
    score[u] += score[v];
    lo[u] = min(lo[u], lo[v]);
  }
  if (u != 0 && graph[u].size() == 1) {
    score[u] = F[u];
    lo[u] = F[u];
    return;
  }
  if (lo[u] < F[u]) {
    score[u] += F[u]-lo[u];
    lo[u] = F[u];
  }
}

void testcase() {
  int n; cin >> n;
  for (int i = 0; i <= n; i++) {
    graph[i].clear();
    score[i] = 0;
    lo[i] = 1e18;
  }
  
  F[0] = 0;
  for (int i = 1; i <= n; i++) cin >> F[i];
  for (int i = 1; i <= n; i++) {
    cin >> P[i];
    int u = i;
    int v = P[i];
    graph[v].push_back(u);
    graph[u].push_back(v);
  }

  dfs(0);
  cout << score[0] << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  for (int x = 1; x <= t; x++) {
    cout << "Case #" << x << ": ";
    testcase();
  }
  return 0;
}
