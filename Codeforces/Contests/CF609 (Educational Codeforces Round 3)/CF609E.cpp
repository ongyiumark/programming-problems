/*
  Find the minimum spanning tree. This answers the query for some edges.
  Then, for edges not part of the MST, we simply need to add the cost of that edge and remove the highest cost
    edge in the path from u to v.
  We can query the highest cost in a path with binary lifting.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,ll> pii;
typedef pair<pair<ll, pair<int,int>>,int> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct edge{
  ll w;
  int u, v;
  int idx;

  bool operator<(const edge& other) const {
    return w < other.w;
  }
};

struct dsu {
  vector<int> p;
  dsu(int n) : p(n,-1){}

  int find(int x){
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
  }

  bool unite(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (p[a] < p[b]) swap(a,b);

    p[b] += p[a];
    p[a] = b;
    return true;
  }
};

const int N = 2e5+5;
edge edges[N], og[N];
int n, m;
bool in_tree[N], vis[N];
ll ans[N];
pii par[20][N];
int dep[N];
dsu union_find(N);
vector<pii> graph[N];

void dfs(int u){
  for (auto p : graph[u]){
    int v = p.first;
    ll w = p.second;
    if (vis[v]) continue;
    vis[v] = true;
    dep[v] = dep[u]+1;
    par[0][v] = {u,w};
    dfs(v);
  }
}

ll find_max(int u, int v){
  if (dep[u] > dep[v]) swap(u, v);
  int diff = dep[v] - dep[u];
  ll ans = 0;
  for (int i = 0; i < 20; i++) {
    if ((1<<i)&diff) {
      ans = max(ans, par[i][v].second);
      v = par[i][v].first;
    }
  }

  int lo = 0;
  int hi = N;
  int up = N;
  while (lo <= hi) {
    int mid = hi - (hi - lo)/2;
    int tmpu = u, tmpv = v;
    for (int i = 0; i < 20; i++) {
      if ((1<<i)&mid){
        tmpu = par[i][tmpu].first;
        tmpv = par[i][tmpv].first;
      }
    }
    if (tmpu == tmpv){
      up = mid;
      hi = mid-1;
    }
    else lo = mid+1;
  }

  for (int i = 0; i < 20; i++) {
    if ((1<<i)&up){
      ans = max({ans, par[i][v].second, par[i][u].second});
      u = par[i][u].first;
      v = par[i][v].first;
    }
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    ll w; int u, v;
    cin >> u >> v >> w;
    u--; v--;
    og[i] = edges[i] = {w,u,v,i};
  }
  memset(in_tree, 0, sizeof in_tree);
  sort(edges, edges+m);

  ll total = 0;
  for (int i = 0; i < m; i++) {
    int u = edges[i].u;
    int v = edges[i].v;
    ll w = edges[i].w;
    int idx = edges[i].idx;

    if (!union_find.unite(u,v)) continue;
    in_tree[idx] = true;
    total += w;
  }

  memset(ans, -1, sizeof ans);
  for (int i = 0; i < m; i++) {
    if (in_tree[i]) {
      ans[i] = total;
      int u = og[i].u; 
      int v = og[i].v;
      ll w = og[i].w;
      graph[u].push_back({v,w});
      graph[v].push_back({u,w});
    }
  }
  
  for (int i = 0; i < n; i++) par[0][i] = {0,0};
  memset(vis, 0, sizeof vis);
  vis[0] = true;
  dep[0] = 0;
  dfs(0);

  for (int d = 1; d < 20; d++) {
    for (int i = 0; i < n; i++) {
      int pv = par[d-1][i].first;
      ll pans = par[d-1][i].second;
      int ppv = par[d-1][pv].first;
      ll ppans = par[d-1][pv].second;
      par[d][i] = {ppv, max(ppans,pans)};
    }
  }
  for (int i = 0; i < m; i++) {
    if (in_tree[i]) continue; 
    
    ans[i] = total + og[i].w - find_max(og[i].u, og[i].v);
  }

  for (int i = 0; i < m; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
