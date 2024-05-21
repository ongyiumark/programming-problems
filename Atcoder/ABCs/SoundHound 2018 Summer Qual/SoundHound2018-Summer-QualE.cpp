/*
  Let node 1 be x. Since the graph is connected, we can write every node as a linear function of x.
  Specifically, either a+x or a-x for some a.

  We DFS through the graph while checking for contradictions.
    (1) If two paths have a+x and b+x where a != b, there is no solution. Similarly for a-x and b-x.
    (2) If two paths have a+x and b-x, x = (b-a)/2. 
      x must be an positive integer and must be valid for all nodes.
  
  If there are no contraditions, we can find the range x = [l,r] that satisfies a+-x > 0 for all a.
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

const int N = 1e5;
struct edge{
  int to, w;
};

vector<edge> adj[N+1];
pair<ll,ll> val[N+1]; // a+x
bool vis[N+1];
ll nums[N+1];

bool check(int u){
  for (edge &e : adj[u]){
    int v = e.to;
    ll w = e.w;
    if (nums[v] != -1){
      if (nums[v]+nums[u] != w) return 0;
      continue;
    }
    nums[v] = w-nums[u];
    if (nums[v] <= 0) return 0;
    if (!check(v)) return 0;
  }
  return 1;
}

bool try_num(ll x){
  memset(nums, -1, sizeof nums);
  nums[1] = x;
  return check(1);
}

int dfs(int u){
  vis[u] = 1;
  for (edge& e : adj[u]){
    int v = e.to;
    ll w = e.w;
    if (vis[v]) {
      pair<ll,ll> a = {-val[u].first, w-val[u].second};
      pair<ll,ll> b = val[v];
      if (a == b) continue;
      if (a.first == b.first && a.second != b.second) return 0;
      if (a.first < 0) swap(a,b);
      int num = b.second-a.second;
      if (num <= 0 || num&1) return 0;
      if (try_num(num/2)) return 1;
      else return 0;
    }
    vis[v] = 1;
    val[v] = {-val[u].first, w-val[u].second};
    int type = dfs(v);
    if (type <= 1) return type;
  }
  return 2;
}

ll solve(int n){
  memset(vis, 0, sizeof vis);
  val[1] = {1,0};
  int type = dfs(1);
  if (type <= 1) return type;

  ll lo = -1e18;
  ll hi = 1e18;
  for (int i = 1; i <= n; i++){
    if (val[i].first > 0) {
      if (val[i].second <= 0) lo = max(-val[i].second+1, lo);
    }
    else {
      hi = min(val[i].second-1, hi);
    }
  }
  if (hi < lo) return 0;
  return hi-lo+1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++){
    int u, v, s;
    cin >> u >> v >> s;
    adj[u].push_back({v,s});
    adj[v].push_back({u,s});
  }
  cout << solve(n) << endl;
  return 0;
}
