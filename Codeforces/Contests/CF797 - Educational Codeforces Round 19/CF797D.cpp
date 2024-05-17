/*
  We can keep track of upperbound and lowerbound as we go down the tree. 
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
const int INF = 1e9;
pair<pair<int,int>,int> T[N];
int par[N];
set<int> can;

void dfs(int idx, int lb, int ub) {
  int v = T[idx].second;
  auto [l,r] = T[idx].first;
  if (lb <= v && v <= ub) can.insert(v);
  if (l != -1) dfs(l, lb, min(v,ub));
  if (r != -1) dfs(r, max(lb,v), ub);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(par, -1, sizeof par);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    int v, l, r; cin >> v >> l >> r;
    T[i] = {{l,r}, v};
    par[l] = i;
    par[r] = i;
  }

  int root = 1;
  while(par[root] != -1) root = par[root];
  dfs(root, -INF, INF);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int v = T[i].second;
    if (can.find(v) == can.end()) ans++;
  }
  cout << ans << endl;
  
  return 0;
}
