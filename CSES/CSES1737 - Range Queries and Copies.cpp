#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// full of memory leaks
template<typename T, T (*Op)(T,T), T eye>
struct SegmentTree {
  int i, j; T val = eye;
  SegmentTree *lc, *rc;
  SegmentTree(int i, int j) : i(i), j(j) {
    if (i == j) {
      val = eye;
      lc = rc = nullptr;
      return;
    }
    int k = (i+j)/2;
    lc = new SegmentTree(i, k);
    rc = new SegmentTree(k+1, j);
    pull();
  }
  void pull() { val = Op(lc->val, rc->val); }
  SegmentTree(int i, int j, 
    SegmentTree *lc, SegmentTree *rc,
    T val) : i(i), j(j), lc(lc), rc(rc), val(val) {}
  
  SegmentTree* update(int x, T v) {
    if (x <= i && j <= x)
      return new SegmentTree(i, j, lc, rc, v);
    else if (j < x || x < i) return this;
    else {
      SegmentTree *nl = lc->update(x, v);
      SegmentTree *nr = rc->update(x, v);
      T nval = Op(nl->val, nr->val);
      return new SegmentTree(i, j, nl, nr, nval);
    }
  }
  T query(int l, int r) {
    if (l <= i && j <= r) return val;
    else if (j < l || r < i) return eye;
    else return Op(lc->query(l,r), rc->query(l,r));
  }

  // optional build from array
  SegmentTree(vector<T> &ar, int i, int j) : i(i), j(j) {
    if (i == j) {
      val = ar[i];
      lc = rc = nullptr;
      return;
    }
    int k = (i+j)/2;
    lc = new SegmentTree(ar, i, k);
    rc = new SegmentTree(ar, k+1, j);
    pull();
  }
};

ll ADD_OP(ll a, ll b) { return a+b; }
using segtree = SegmentTree<ll, ADD_OP, 0>;

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int n, q; cin >> n >> q;
  vector<ll> t(n);
  for (ll &x : t) cin >> x;

  vector<segtree*> sts;
  sts.push_back(new segtree(t, 0, n-1));
  while(q--) {
    int op; cin >> op;
    if (op == 1) {
      int k, a, x; cin >> k >> a >> x;
      k--; a--;
      sts[k] = sts[k]->update(a, x);
    }
    else if (op == 2) {
      int k, a, b; cin >> k >> a >> b;
      k--; a--; b--;
      cout << sts[k]->query(a, b) << "\n";
    }
    else {
      int k; cin >> k; k--;
      sts.push_back(sts[k]);
    }
  }



  return 0;
}