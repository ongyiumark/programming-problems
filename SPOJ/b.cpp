#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
struct Node {
  int i, j; T val;
  int lc, rc;
};

// all static functions
template<typename T, T (*Op)(T,T), T eye>
struct SegmentTree {
  static vector<Node<T>> inline nodes;
  static int inline counter = 0;

  static int make_segtree(int i, int j, 
  T val=eye, int lc=-1, int rc=-1) {
    nodes.push_back({i, j, val, lc, rc});
    return counter++;
  }
  static int build(int i, int j) {
    if (i == j) return make_segtree(i, j);
    int k = (i+j)/2;
    int lc = build(i, k), rc = build(k+1, j);
    return make_segtree(i, j, 
      Op(nodes[lc].val, nodes[rc].val), lc, rc);
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
    return make_segtree(i, j, 
      Op(nodes[lc].val, nodes[rc].val), lc, rc);
  }
};

int ADD_OP(int a, int b) { return a+b; }
using segtree = SegmentTree<int, ADD_OP, 0>;
struct LeqCounter {
  map<ll, int> roots;
  vector<ll> neg_nums;
  LeqCounter(vector<ll> &ar) {
    int n = ar.size();
    vector<pair<ll,int>> nums;
    for (int i = 0; i < n; i++) {
      nums.push_back({ar[i], i});
      neg_nums.push_back(-ar[i]);
    }
    sort(nums.begin(), nums.end());
    sort(neg_nums.begin(), neg_nums.end());
    ll pv = 0;
    roots[pv] = segtree::build(0, n-1);
    for (auto &[val, idx] : nums) {
      roots[val] = segtree::update(roots[pv], idx, 1);
      pv = val;
    }
  }
  int count(int l, int r, ll x) {
    auto it = lower_bound(neg_nums.begin(), neg_nums.end(), -x);
    if (it == neg_nums.end()) return 0;
    return segtree::query(roots[-(*it)], l, r);
  }
};

const ll INF = 1e18;
int main() {
  cin.tie(0)->sync_with_stdio(false);

  int n, m; cin >> n >> m;
  vector<ll> ar(n);
  for (ll &x : ar) cin >> x;
  LeqCounter leqc(ar);
  for (int i = 0; i < m; i++) {
    int l, r, k; cin >> l >> r >> k;
    l--; r--;

    ll lo = -INF;
    ll hi = INF;
    ll res = 0;
    while (lo <= hi) {
      ll mid = hi - (hi-lo)/2;
      if (leqc.count(l, r, mid) >= k) {
        res = mid;
        hi = mid-1;
      } 
      else lo = mid+1;
    }
    cout << res << "\n";
  }
}