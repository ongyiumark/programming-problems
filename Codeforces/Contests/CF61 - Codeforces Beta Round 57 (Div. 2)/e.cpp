#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
struct Node {
  int i, j; T val;
  int lc, rc;
  Node() {}
  Node(int i, int j, T val, int lc, int rc)
    : i(i), j(j), val(val), lc(lc), rc(rc) {}
};
const int MAXN = 2e7;

// all static functions
template<typename T, T (*Op)(T,T), T eye>
struct SegmentTree {
  static vector<Node<T>> inline nodes;
  static int inline counter = 0;

  static void reserve() { nodes.assign(MAXN, Node<T>()); }

  static int make_node(int i, int j, 
  T val=eye, int lc=-1, int rc=-1) {
    nodes[counter] = {i, j, val, lc, rc};
    return counter++;
  }
  static int build(int i, int j) {
    if (i == j) return make_node(i, j);
    int k = (i+j)/2;
    int lc = build(i, k), rc = build(k+1, j);
    return make_node(i, j, 
      Op(nodes[lc].val, nodes[rc].val), lc, rc);
  }
  static int update(int node_idx, int x, T v) {
    auto [i, j, val, lc, rc] = nodes[node_idx];
    if (x <= i && j <= x)
      return make_node(i, j, v, lc, rc);
    else if (j < x || x < i) return node_idx;
    else {
      int nl = update(lc, x, v);
      int nr = update(rc, x, v);
      T nval = Op(nodes[nl].val, nodes[nr].val);
      return make_node(i, j, nval, nl, nr);
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
    if (i == j) return make_node(i, j, ar[i]);
    int k = (i+j)/2;
    int lc = build(ar, i, k), rc = build(ar, k+1, j);
    return make_node(i, j, 
      Op(nodes[lc].val, nodes[rc].val), lc, rc);
  }
};

int ADD_OP(int a, int b) { return a+b; }
using segtree = SegmentTree<int, ADD_OP, 0>;
struct LeqCounter {
  // map<ll, segtree*> roots;
  map<int, int> roots;
  vector<int> neg_nums;
  LeqCounter(vector<int> &ar) {
    int n = ar.size();
    vector<pair<int,int>> nums;
    for (int i = 0; i < n; i++) {
      nums.push_back({ar[i], i});
      neg_nums.push_back(-ar[i]);
    }
    sort(nums.begin(), nums.end());
    sort(neg_nums.begin(), neg_nums.end());
    int pv = 0;
    // roots[pv] = segtree(0, n-1);
    roots[pv] = segtree::build(0, n-1);
    for (auto &[val, idx] : nums) {
      //roots[val] = roots[pv]->update(idx, 1);
      roots[val] = segtree::update(roots[pv], idx, 1);
      pv = val;
    }
  }
  int count(int l, int r, int x) {
    auto it = lower_bound(neg_nums.begin(), 
                          neg_nums.end(), -x);
    if (it == neg_nums.end()) return 0;
    // return roots[-(*it)]->query(l, r);
    return segtree::query(roots[-(*it)], l, r);
  }
};

struct GeqCounter {
  // map<int, segtree*> roots;
  map<int, int> roots;
  vector<int> neg_nums;
  GeqCounter(vector<int> &ar) {
    int n = ar.size();
    vector<pair<int,int>> nums;
    for (int i = 0; i < n; i++) {
      nums.push_back({ar[i], i});
      neg_nums.push_back(ar[i]);
    }
    sort(nums.begin(), nums.end(), greater<pair<int,int>>());
    sort(neg_nums.begin(), neg_nums.end());
    int pv = 0;
    // roots[pv] = segtree(0, n-1);
    roots[pv] = segtree::build(0, n-1);
    for (auto &[val, idx] : nums) {
      //roots[val] = roots[pv]->update(idx, 1);
      roots[val] = segtree::update(roots[pv], idx, 1);
      pv = val;
    }
  }
  int count(int l, int r, int x) {
    auto it = lower_bound(neg_nums.begin(), 
                          neg_nums.end(), x);
    if (it == neg_nums.end()) return 0;
    // return roots[-(*it)]->query(l, r);
    return segtree::query(roots[(*it)], l, r);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(false);
  segtree::reserve();

  int n; cin >> n;
  vector<int> ar(n);
  for (int &x : ar) cin >> x;
  LeqCounter leq(ar);
  GeqCounter geq(ar);
  ll ans = 0;
  for (int i = 1; i < n-1; i++) {
    //cout << i << " " << ar[i] << " - " << geq.count(0, i-1, ar[i]-1) << " " <<leq.count(i+1, n-1, ar[i]+1) << endl;
    ans += (ll)geq.count(0, i-1, ar[i]+1)*(ll)leq.count(i+1, n-1, ar[i]-1);
  }
  cout << ans << "\n";

  return 0;
}