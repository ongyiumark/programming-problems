#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

struct SegmentTree {
  int n;
  vector<int> st;
  vector<vector<int>> lazy;
  SegmentTree(int n) : n(n), st(4*n), lazy(4*n, vector(2,0LL)) {}
  SegmentTree(const vector<int> &ar) {
    n = ar.size();
    st.assign(4*n, 0); lazy.assign(4*n, vector(2, 0LL));
    build(ar, 1, 0, n-1);
  }

  void build(const vector<int>& ar, int p, int i, int j) {
    if (i == j) {
      st[p] = ar[i];
      return;
    }
    int k = (i+j)/2;
    build(ar, p<<1, i, k);
    build(ar, p<<1|1, k+1, j);
    pull(p);
  }

  void pull(int p) { st[p] = st[p<<1] + st[p<<1|1]; }
  void push(int p, int i, int j) {
    int cnt = count_if(lazy[p].begin(), lazy[p].end(), [](const int& x){ return (x != 0); });
    if (cnt) {
      st[p] += (i*(j-i+1) + (j-i+1)*(j-i+2)/2)*lazy[p][0] + lazy[p][1]*(j-i+1);
      if (i != j) {
        for (int kk = 0; kk < 2; kk++) {
          lazy[p<<1][kk] += lazy[p][kk];
          lazy[p<<1|1][kk] += lazy[p][kk];
        }
      }
      for (int kk = 0; kk < 2; kk++) lazy[p][kk] = 0;
    }
  }

  void update(int l, int r, int v) { 
    update(l, r, v, 1, 0, n-1); 
  }
  void update(int l, int r, int v, int p, int i, int j) {
    push(p, i, j);
    if (l <= i && j <= r) {
      lazy[p][0] += 1;
      lazy[p][1] -= l;
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

  int query(int l, int r) { return query(l, r, 1, 0, n-1); }
  int query(int l, int r, int p, int i, int j) {
    push(p, i, j);
    if (l <= i && j <= r) { return st[p]; }
    else if (j < l || r < i) { return 0; }
    else {
      int k = (i+j)/2;
      return query(l, r, p<<1, i, k) 
        + query(l, r, p<<1|1, k+1, j);
    }
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(false);
  int n, q; cin >> n >> q;

  
  vector<ll> t(n);
  for (int &x : t) cin >> x;
  SegmentTree st(t);

  while(q--) {
    int op, a, b; cin >> op >> a >> b;
    a--; b--;
    if (op == 1) st.update(a, b, 1);
    else cout << st.query(a, b) << "\n";
  }

  return 0;
}