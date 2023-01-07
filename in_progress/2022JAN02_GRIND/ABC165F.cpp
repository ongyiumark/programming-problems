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
int a[N];
vector<int> graph[N];
int n; 

vector<int> lis;
int ans[N];

void dfs(int u, int p) {
  ans[u] = lis.size();

  for (int v : graph[u]) {
    if (v == p) continue;

    // change
    int j = lower_bound(lis.begin(), lis.end(), a[v]) - lis.begin();
    int sz = lis.size();
    int og;
    if (j == sz) lis.push_back(a[v]);
    else og = lis[j], lis[j] = a[v];

    // recurse
    dfs(v, u);

    // backtrack
    if (j == sz) lis.pop_back();
    else lis[j] = og;
  }
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n-1; i++) {
    int u, v; cin >> u >> v;
    u--; v--;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  lis.push_back(a[0]);
  dfs(0, -1);
  lis.pop_back();

  for (int i = 0; i < n; i++) {
    cout << ans[i] << "\n";
  }
  return 0;
}
