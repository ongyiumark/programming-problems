#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
  void pull() { val = Op(lc->val, rc->val); }
  SegmentTree(int i, int j, 
    SegmentTree *lc, SegmentTree *rc,
    T val) : i(i), j(j), lc(lc), rc(rc), val(val) {}
  
  SegmentTree* update(int x, T v) {
    if (x <= i && j <= x)
      return new SegmentTree(i, j, lc, rc, Op(val, v));
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
};

int ADD_OP(int a, int b) { return a+b; }
using segtree = SegmentTree<int, ADD_OP, 0>;
const ll INF = 1e18;
struct LeqCounter {
  map<ll, segtree*> roots;
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
    ll pv = -INF;
    roots[pv] = new segtree(0, n);
    for (auto &[val, idx] : nums) {
      roots[val] = roots[pv]->update(idx, 1);
      pv = val;
    }
  }
  int count(int l, int r, ll x) {
    auto it = lower_bound(neg_nums.begin(), neg_nums.end(), -x);
    if (it == neg_nums.end()) return 0;
    return roots[-(*it)]->query(l, r);
  }
};

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