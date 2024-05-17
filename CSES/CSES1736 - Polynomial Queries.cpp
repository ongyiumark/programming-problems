#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

// point update, range query
struct FenwickTree {
  vector<ll> ft;
  FenwickTree(int n) : ft(n+1) {}
  ll query(int i) {
    ll total = 0;
    for (; i > 0; i -= (i&-i)) total += ft[i];
    return total;
  }
  ll query(int l, int r) { return query(r)-query(l-1); }
  void update(int i, ll v) {
    for (; i < ft.size(); i += (i&-i)) 
      ft[i] += v;
  }
};

// range update, point query
struct FenwickRUPQ {
  FenwickTree ft;
  FenwickRUPQ(int m) : ft(m) {}
  void update(int l, int r, ll v) {
    ft.update(l, v); ft.update(r+1, -v);
  }
  int query(int i) { return ft.query(i); }
};

// range update, range query
struct Fenwick {
  vector<FenwickRUPQ> ft; 
  int n;

  Fenwick(int n) : ft(3, FenwickRUPQ(n)), n(n) {}

  // i^2 + (3-2l)i + (l^2-3l+2)
  void update(int l, int r, ll v) {
    ft[0].update(l, r, 1*v); 
    ft[1].update(l, r, (3-2*l)*v);
    ft[2].update(l, r, (l*l-3*l+2)*v);
    if (r+1 <= n) ft[2].update(r+1, n, ((r-l+1)*(r-l+2))*v);
  }
  ll query(int i) { 
    ll twice = ft[0].query(i)*i*i + ft[1].query(i)*i + ft[2].query(i); 
    return twice/2;
  }
  ll query(int l, int r) { return query(r) - query(l-1); }
};

signed main() {
  cin.tie(0)->sync_with_stdio(false);
  int n, q; cin >> n >> q;

  Fenwick ft(n);
  for (int i = 1; i <= n; i++) {
    ll x; cin >> x;
    ft.update(i, i, x);
  }
  while(q--) {
    int op, a, b; cin >> op >> a >> b;
    if (op == 1) ft.update(a, b, 1);
    else cout << ft.query(a, b) << "\n";
  }

  return 0;
}