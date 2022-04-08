/*  
  You can topological sort the tree into an array.
  The queries now become range queries in this array.
  
  We can do this quicly with a segtree.
  Since we only need know if a color exists in a subtree, we can use bitsets.
    Using sets with this method would be too slow.
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

const int N = 4e5+5;
vector<int> graph[N];

vector<int> toposort;
int st[N];
int idx_to_seg[N];

void dfs(int u, int p) {
  st[u] = 1;
  for (int v : graph[u]){
    if (v == p) continue;
    dfs(v, u);
    st[u]+=st[v];
  }
  toposort.push_back(u);
}

struct colors {
  bitset<61> c;
  colors() {}
  colors(int i) {
    c.set(i);
  }

  void reset() {
    c.reset();
  }

  bool exists() {
    return c.count() > 0;
  }

  colors operator+(const colors &other) const{
    colors res = colors();
    res.c = (c | other.c);
    return res;
  }
};
vector<colors> cols(N);


struct segtree {
  int n; 
  colors *vals, *deltas;
  segtree(vector<colors> &ar){
    n = ar.size();
    vals = new colors[4*n];
    deltas = new colors[4*n];
    build(ar, 1, 0, n-1);
  }

  void build(vector<colors> &ar, int p, int i, int j) {
    deltas[p].reset();
    if (i == j) {
      vals[p] = ar[i];
    }
    else {
      int k = (i+j)/2;
      build(ar, p<<1, i, k);
      build(ar, p<<1|1, k+1, j);
      pull(p);
    }
  }

  void pull(int p) {
    vals[p] = vals[p<<1] + vals[p<<1|1];
  }

  void push(int p, int i, int j) {
    if (deltas[p].exists()) {
      vals[p] = deltas[p];
      if (i != j) {
        deltas[p<<1] = deltas[p];
        deltas[p<<1|1] = deltas[p];
      }
      deltas[p].reset();
    }
  }

  void update(int _i, int _j, int v, int p, int i, int j) {
    push(p, i, j);
    if (_i <= i && j <= _j) {
      deltas[p] = colors(v);
      push(p, i, j);
    }
    else if (_j < i || j < _i) {}
    else {
      int k = (i+j)/2;
      update(_i, _j, v, p<<1, i, k);
      update(_i, _j, v, p<<1|1, k+1,j);
      pull(p);
    }
  }

  colors query(int _i, int _j, int p, int i, int j) {
    push(p, i, j);
    if (_i <= i && j <= _j) return vals[p];
    if (_j < i || j < _i) return colors();
    
    int k = (i+j)/2;
    return query(_i, _j, p<<1, i, k) + query(_i, _j, p<<1|1, k+1, j);
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int col; cin >> col;
    cols[i] = colors(col);
  }
  // Build graph.
  for (int i = 0; i < n-1; i++) {
    int u, v; cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  // Sort topologically.
  // Subtree of i is the previous ar[idx[i]-st[i]+1:idx[i]].
  dfs(1,-1);
  for (int i = 0; i < n; i++) {
    idx_to_seg[toposort[i]] = i;
  }

  // Build segment tree.
  vector<colors> ar(n);
  for (int i = 0; i < n; i++) {
    ar[i] = cols[toposort[i]];
  }
  segtree stree(ar);


  for (int i = 0; i < m; i++) {
    int t; cin >> t;
    if (t == 1) {
      int v, col; cin >> v >> col;
      int r = idx_to_seg[v];
      int l = r-st[v]+1;

      // Change l to r into col.
      stree.update(l, r, col, 1, 0, n-1);
    }
    else {
      int v; cin >> v;
      int r = idx_to_seg[v];
      int l = r-st[v]+1;

      // Count how many colors from l to r.
      colors q = stree.query(l, r, 1, 0, n-1);
      cout << q.c.count() << endl;
    }
  }

  return 0;
}
