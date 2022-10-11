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
vector<pii> edges;
vector<int> graph[N];

struct dsu {
  vector<int> p;
  dsu(int n): p(n, -1) {}

  int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
  }

  bool unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return false;
    if (p[a] >= p[b]) swap(a,b);

    p[a] += p[b];
    p[b] = a;

    return true;
  } 
};

vector<int> solve(int u, int p) {
  vector<int> res;
  vector<vector<int>> children;

  int idx = 0, bidx = 0, best = 0;
  for (int v : graph[u]) {
    if (v == p) continue;
    vector<int> child = solve(v, u);
    children.push_back(child);
    int sz = child.size();
    if (best < sz) {
      best = sz;
      bidx = idx;
    }
    idx++;
  }

  if (idx > 0) {
    swap(res, children[bidx]);
    for (int i = 0; i < idx; i++) {
      if (i == bidx) continue;
      for (int v : children[i]) {
        res.push_back(v);
      }
    }
  }
  res.push_back(u);

  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    a--; b--;
    if (a >= b) swap(a,b);
    edges.push_back({a,b});
  }

  dsu df(n);
  vector<pii> tree;
  for (int i = 0; i < m; i++) {
    int u = edges[i].first;
    int v = edges[i].second;
    if (df.unite(u,v)) tree.push_back({u,v});
  }

  for (auto e : tree) {
    int u = e.first;
    int v = e.second;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  vector<int> ans = solve(0, -1);
  cout << ans.size() << " " << n << endl;
  for (int i = 0; i < n; i++) {
    cout << ans[i]+1;
    if (i < n-1) cout << " ";
    else cout << "\n";
  }
  
  return 0;
}
