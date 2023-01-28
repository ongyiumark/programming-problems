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
int A[N], B[N];
vector<int> graph[N];
int du[N], dv[N];

void dfs(int* d, int u, int p) {
  for (int v : graph[u]) {
    if (v == p) continue;
    d[v] = d[u]+1;
    dfs(d, v, u);
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  int u, v; cin >> u >> v;
  u--; v--;
  for (int i = 0; i < n-1; i++) {
    cin >> A[i] >> B[i];
    A[i]--; B[i]--;
    graph[A[i]].push_back(B[i]);
    graph[B[i]].push_back(A[i]);
  }

  dv[v] = 0;
  dfs(dv, v, -1);

  du[u] = 0;
  dfs(du, u, -1);

  int hi = 0;
  for (int i = 0; i < n; i++) {
    if (du[i] >= dv[i]) continue;
    hi = max(hi, dv[i]);
  }
  cout << hi-1 << "\n";
  
  return 0;
}
