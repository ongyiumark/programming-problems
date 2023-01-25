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
int a[N], b[N];
vector<int> idx[N];
const int MOD = 998244353;
bool vis[N], check[N];

struct dsu {
  vector<int> p;
  dsu(int n) : p(n, -1) {}

  void reset(int m) {
    for (int i = 0; i < m; i++) {
      p[i] = -1;
    } 
  }

  int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
  }

  bool unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;

    if (p[u] > p[v]) swap(u, v);
    p[u] += p[v];
    p[v] = u;

    return true;
  }
};

dsu uf(N);
vector<int> graph[N];

void dfs(int u) {
  int sz = idx[u].size();
  if (check[u]) return;
  if (sz == 0) return;
  else if (sz == 1) check[u] = 1;
  else {
    check[u] = 1;
    for (int j = 0; j < sz; j++) {
      int v = idx[u][j];
      check[a[v]] = check[b[v]] = 1;
      dfs(a[v]);
      dfs(b[v]);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) idx[i].clear();
    for (int i = 0; i <= n; i++) vis[i] = check[i] = 0;
    for (int i = 0; i <= n; i++) graph[i].clear();

    for (int i = 0; i < n; i++) {
      idx[a[i]].push_back(i);
      idx[b[i]].push_back(i);

      graph[a[i]].push_back(b[i]);
      graph[b[i]].push_back(a[i]);
    }
    uf.reset(n);

    for (int i = 1; i <= n; i++) {
      int sz = idx[i].size();
      for (int j = 1; j < sz; j++) {
        uf.unite(idx[i][j-1], idx[i][j]);
      }
    }

    for (int i = 1; i <= n; i++) {
      if (check[i]) continue;
      dfs(i);
    }

    bool val = 1;
    for (int i = 1; i <= n; i++) val &= check[i];

    if (!val) {
      cout << 0 << "\n";
      continue;
    }

    ll ans = 1;
    for (int i = 0; i <= n; i++) vis[i] = 0;
    for (int i = 0; i < n; i++) {
      int p = uf.find(i);
      if (vis[p]) continue;

      if (a[i] == b[i]) {
        ans *= n;
        ans %= MOD;
      }
      else {
        ans *= 2;
        ans %= MOD;
      }      

      vis[p] = 1;
    }

    cout << ans << "\n";
  }
  
  return 0;
}
