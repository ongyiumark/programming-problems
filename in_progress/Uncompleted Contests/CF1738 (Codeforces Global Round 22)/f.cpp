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

struct dsu {
  vi p;
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

int query(int u) {
  cout << "? " << u << endl;
  int res; cin >> res;
  return res;
}

void testcase() {
  int n; cin >> n;
  int d[n];
  ii degs[n];
  for (int i = 0; i < n; i++) cin >> d[i];
  for (int i = 0; i < n; i++) degs[i] = {d[i], i};
  sort(degs, degs+n, greater<ii>());

  dsu uf(n);
  vector<bool> vis(n);
  
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int u = degs[i].second;
    int sz = degs[i].first;

    if (vis[u]) continue;
    vis[u] = 1;
    for (int k = 0; k < sz; k++) {
      int v = query(u+1);
      cnt++;
      uf.unite(u, v-1);
      //if (vis[v-1]) break;
      vis[v-1] = 1;
      if (cnt == n) break;
    }
    if (cnt == n) break;
  }

  cout << "!";
  for (int i = 0; i < n; i++) {
    
    cout << " " << uf.find(i)+1;
  }
  cout << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--) testcase();
  
  return 0;
}
