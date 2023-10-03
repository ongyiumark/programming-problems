#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef tuple<ll,ll,ll> node;

const ll INF = 1e9+7;

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
  ll g = gcd(a,b);
  if (g == 0) return 0;
  return a/g*b;
}

node combine(node l, node r) {
  auto [l1,l2,l3] = l;
  auto [r1,r2,r3] = r;

  ll k1 = gcd(l1, r1);
  ll k2 = lcm(gcd(l1, r2), gcd(r1, l2));
  ll k3 = lcm(lcm(gcd(l1,r3), gcd(r1,l3)), gcd(r2,l2));

  return {k1, k2, k3};
}

struct segtree {
  vector<node> vals;
  segtree(vector<ll> &ar) {
    int n = ar.size();
    vector<node>(4*n).swap(vals);

    build(ar, 1, 0, n-1);
  }

  void build(vector<ll> &ar, int p, int i, int j) {
    if (i == j) {
      vals[p] = {ar[i], 0, 0};
      return;
    }

    int k = (i+j)>>1;
    build(ar, p<<1, i, k);
    build(ar, p<<1|1, k+1, j);
    pull(p);
  }

  void pull(int p) {
    auto [l1,l2,l3] = vals[p<<1];
    auto [r1,r2,r3] = vals[p<<1|1];

    ll k1 = gcd(l1, r1);
    ll k2 = lcm(gcd(l1, r2), gcd(r1, l2));
    ll k3 = lcm(lcm(gcd(l1,r3), gcd(r1,l3)), gcd(r2,l2));

    vals[p] = {k1, k2, k3};
  }

  void update(int idx, ll x, int p, int i, int j) {
    if (i == j && idx == i) {
      vals[p] = {x, 0, 0};
    }
    else if (j < idx || idx < i) {}
    else {
      int k = (i+j)>>1;
      update(idx, x, p<<1, i, k);
      update(idx, x, p<<1|1, k+1, j);
      pull(p);
    }
  }

  node query(int l, int r, int p, int i, int j) {
    if (l <= i && j <= r) return vals[p];
    else if (j < l || r < i) return {0, 0, 0};
    else {
      int k = (i+j)>>1;
      return combine(query(l, r, p<<1, i, k), query(l, r, p<<1|1, k+1, j));
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m; cin >> n >> m;
  vector<ll> ar(n);
  for (int i = 0; i < n; i++) cin >> ar[i];
  segtree st(ar);

  for (int i = 0; i < m; i++) {
    char t; cin >> t;
    if (t == 'U') {
      int j, x; cin >> j >> x;
      j--;
      st.update(j, x, 1, 0, n-1);
    }
    else {
      int l, r, k; cin >> l >> r >> k;
      l--; r--;
      node res = st.query(l, r, 1, 0, n-1);

      ll ans = 0;
      if (k == 0) ans = get<0>(res);
      else if (k == 1) ans = get<1>(res);
      else ans = get<2>(res);

      cout << ans << endl; 
    }
  }

  return 0;
}