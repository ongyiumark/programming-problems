#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct SegmentTree {
  ll INF = 1e18;
  int n; vector<ll> st, lazy;
  SegmentTree(int n) : n(n), st(4*n), lazy(4*n, INF) {}
  void pull(int p) { st[p] = st[p<<1] + st[p<<1|1]; }
  void push(int p, int i, int j) {
    if (lazy[p] != INF) {
      st[p] = (j-i+1)*lazy[p];
      if (i != j) {
        lazy[p<<1] = lazy[p];
        lazy[p<<1|1] = lazy[p];
      }
      lazy[p] = INF;
    }
  }
  void update(int l, int r, ll v) {
    update(l, r, v, 1, 0, n-1);
  }
  void update(int l, int r, ll v, int p, int i, int j) {
    push(p, i, j);
    if (l <= i && j <= r) {
      lazy[p] = v;
      push(p, i, j);
    }
    else if (j < l || r < i) {}
    else {
      int k = (i+j)/2;
      update(l, r, v, p<<1, i, k);
      update(l, r, v, p<<1|1, k+1, j);
      pull(p);
    }
  }
  ll query(int l, int r) { return query(l, r, 1, 0, n-1); }
  ll query(int l, int r, int p, int i, int j) {
    push(p, i, j);
    if (l <= i && j <= r) {
      return st[p];
    }
    else if (j < l || r < i) { return 0; }
    else {
      int k = (i+j)/2;
      return query(l, r, p<<1, i, k) + query(l, r, p<<1|1, k+1, j);
    }
  }

  SegmentTree(const vector<ll> &ar) {
    n = ar.size();
    st.assign(4*n, 0); lazy.assign(4*n, INF);
    build(ar, 1, 0, n-1);
  }

  void build(const vector<ll> &ar, int p, int i, int j) {
    if (i == j) {
      st[p] = ar[i];
      return;
    }
    int k = (i+j)/2;
    build(ar, p<<1, i, k);
    build(ar, p<<1|1, k+1, j);
    pull(p);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int n; cin >> n;
  vector<ll> X(n);
  for (ll &x : X) cin >> x;
  for (int i = 0; i < n; i++) {
    X[i] -= i;
  }
  SegmentTree segtree(X);

  ll ans = 0;
  int q; cin >> q;
  while (q--) {
    int t; ll G;
    cin >> t >> G;
    t--;

    ll pos = segtree.query(t, t);
    if (pos <= G-t) {
      int l = t;

      // binary search r
      int r = t;
      int lo = t;
      int hi = n-1;
      while (lo <= hi) {
        int mid = hi - (hi-lo)/2;
        if (segtree.query(mid, mid) <= G-l) {
          r = mid;
          lo = mid+1;
        }
        else hi = mid-1;
      }
      ll cost = (G-l)*(r-l+1) - segtree.query(l, r);
      segtree.update(l, r, G-l);
      ans += cost;
    }
    else {
      int r = t;
      
      // binary search l
      int l = t;
      int lo = 0;
      int hi = t;
      while (lo <= hi) {
        int mid = hi - (hi-lo)/2;
        if (segtree.query(mid, mid) >= G-r) {
          l = mid;
          hi = mid-1;
        }
        else lo = mid+1;
      }

      ll cost = segtree.query(l, r) - (G-r)*(r-l+1);
      segtree.update(l, r, G-r);
      ans += cost;
    }
  }
  cout << ans << "\n";
  
  return 0;
}