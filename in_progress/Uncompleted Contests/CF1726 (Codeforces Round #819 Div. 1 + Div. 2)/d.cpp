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

const int N = 2e5+5;

struct edge {
  int u, v, i, deg;
  bool operator<(const edge &other) const {
    if (deg == other.deg) {
      return pair<int,int>(u,v) < pair<int,int>(other.u, other.v);
    }
    return deg > other.deg;
  }
};

struct dsu {
  vector<int> p;
  dsu(int n) : p(n,-1) {}
  int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
  }

  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (p[a] > p[b]) swap(a,b);
    p[a] += p[b];
    p[b] = a;
    return true;
  }
};  

edge edges[N];
bool ans[N];
int deg[N];

void testcase() {
  int n, m; cin >> n >> m;
  
  for (int i = 0; i < n; i++) deg[i] = 0;
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    u--; v--;
    deg[u]++; deg[v]++;
    edges[i] = {min(u,v),max(u,v),i};
  }

  for (int i = 0; i < m; i++) {
    edges[i].deg = max(deg[edges[i].u], deg[edges[i].v]);
  }

  for (int i = 0; i < m; i++) {
    ans[i] = 0;
  }

  dsu uf(n);
  sort(edges, edges+m);
  for (int i = 0; i < m; i++) {
    bool res = uf.unite(edges[i].u, edges[i].v);
    if (res) ans[edges[i].i] = 1;
  }
  
  for (int i = 0; i < m; i++) {
    cout << ans[i];
  }
  cout << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--) {
    testcase();
  }
  return 0;
}
