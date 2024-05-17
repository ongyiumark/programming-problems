#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
struct Node {
  int i, j; T val;
  int lc, rc;
};

template<typename T, T (*Op)(T,T), T eye>
struct SegmentTree {
  static vector<Node<T>> inline nodes;
  static int inline counter = 0;

  static int make_segtree(int i, int j, T val=eye, int lc=-1, int rc=-1) {
    nodes.push_back({i, j, val, lc, rc});
    return counter++;
  }

  static int build(int i, int j) {
    if (i == j) return make_segtree(i, j);
    int k = (i+j)/2;
    int lc = build(i, k), rc = build(k+1, j);
    return make_segtree(i, j, Op(nodes[lc].val, nodes[rc].val), lc, rc);
  }
  
  static int update(int node_idx, int x, T v) {
    auto [i, j, val, lc, rc] = nodes[node_idx];
    if (x <= i && j <= x)
      return make_segtree(i, j, v, lc, rc);
    else if (j < x || x < i) return node_idx;
    else {
      int nl = update(lc, x, v);
      int nr = update(rc, x, v);
      T nval = Op(nodes[nl].val, nodes[nr].val);
      return make_segtree(i, j, nval, nl, nr);
    }
  }
  static T query(int node_idx, int l, int r) {
    auto [i, j, val, lc, rc] = nodes[node_idx];
    if (l <= i && j <= r) return val;
    else if (j < l || r < i) return eye;
    else return Op(query(lc,l,r), query(rc,l,r));
  }

  // optional build from array
  static int build(vector<T> &ar, int i, int j) {
    if (i == j) return make_segtree(i, j, ar[i]);
    int k = (i+j)/2;
    int lc = build(ar, i, k), rc = build(ar, k+1, j);
    return make_segtree(i, j, Op(nodes[lc].val, nodes[rc].val), lc, rc);
  }
};

ll ADD_OP(ll a, ll b) { return a+b; }
using segtree = SegmentTree<ll, ADD_OP, 0>;

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int n, q; cin >> n >> q;
  vector<ll> t(n);
  for (ll &x : t) cin >> x;

  vector<int> sts;
  sts.push_back(segtree::build(t, 0, n-1));
  while(q--) {
    int op; cin >> op;
    if (op == 1) {
      int k, a, x; cin >> k >> a >> x;
      k--; a--;
      sts[k] = segtree::update(sts[k], a, x);
    }
    else if (op == 2) {
      int k, a, b; cin >> k >> a >> b;
      k--; a--; b--;
      cout << segtree::query(sts[k], a, b) << "\n";
    }
    else {
      int k; cin >> k; k--;
      sts.push_back(sts[k]);
    }
  }



  return 0;
}