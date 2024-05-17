#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

template<typename T, T (*Op)(T,T), T Identity>
struct SegmentTree {
  vector<T> st; int n;
  SegmentTree(vector<T> &ar) {
    n = ar.size(); st.assign(2*n, Identity);
    for (int i = 0; i < n; i++) st[i+n] = ar[i];
    for (int p = n-1; p > 0; p--) 
      st[p] = Op(st[p<<1], st[p<<1|1]);
  }
  SegmentTree(int n) : n(n), st(2*n, Identity) {}
  void update(int p, T v) {
    for (st[p += n] = v; p >>= 1; )
      st[p] = Op(st[p<<1], st[p<<1|1]);
  }
  T query(int l, int r) {
    T resl = Identity, resr = Identity;
    for (l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
      if (l&1) resl = Op(resl, st[l++]);
      if (r&1) resr = Op(st[--r], resr);
    }
    return Op(resl, resr);
  }
};

ll GCD_OP(ll a, ll b) { return b ? GCD_OP(b, a%b) : a; }
ll MAX_OP(ll a, ll b) { return max(a, b); }
ll MIN_OP(ll a, ll b) { return min(a, b); }
const ll INF = 1e18;
struct DuplicateST {
  SegmentTree<ll, MIN_OP, INF> st;
  vector<ll> val;
  map<ll, set<int>> idx_of_val;
  DuplicateST(vector<ll> &ar) : st(ar.size()), 
                                val(ar.size()) {
    int n = ar.size();
    for (int i = 0; i < n; i++) add(i, ar[i]);
  }
  // assume all values are 0
  DuplicateST(int n) : st(n), val(n) {
    for (int i = 0; i < n; i++) {
      idx_of_val[0].insert(i);
      st.update(i, i+1 < n ? i+1 : INF);
    }
  }
  void add(int i, ll v) {
    val[i] = v;
    auto &pos = idx_of_val[val[i]];
    auto right = pos.upper_bound(i);
    st.update(i, (right == pos.end() ? INF : *right));
    if (right != pos.begin()) st.update(*prev(right), i);
    pos.insert(i);
  }
  bool has_duplicate(int l, int r) {
    return st.query(l, r) <= r;
  }
  void update(int i, ll v) {
    auto &old_pos = idx_of_val[val[i]];
    old_pos.erase(i);
    auto old_right = old_pos.upper_bound(i);
    if (old_right != old_pos.begin()) {
      st.update(*prev(old_right), 
        (old_right == old_pos.end()) ? INF : *old_right);
    }
    add(i, v);
  }
};


int main() {
  cin.tie(0)->sync_with_stdio(false);

  int n, q; cin >> n >> q;
  vector<ll> T(n);
  for (ll &x : T) cin >> x;
  vector<ll> dT(n-1);
  for (int i = 0; i < n-1; i++) dT[i] = abs(T[i+1]-T[i]);

  SegmentTree<ll, GCD_OP, 0> gcd_st(dT);
  SegmentTree<ll, MAX_OP,-INF> max_st(T);
  SegmentTree<ll, MIN_OP, INF> min_st(T);
  DuplicateST dup_st(T); // store next appearance in the same position
  
  for (int qq = 0; qq < q; qq++) {
    int op; cin >> op;
    if (op == 1) {
      ll x, y; cin >> x >> y;
      x--;

      T[x] = y;
      min_st.update(x, T[x]);
      max_st.update(x, T[x]);
      dup_st.update(x, T[x]);

      if (x-1 >= 0) gcd_st.update(x-1, abs(T[x]-T[x-1]));
      if (x+1 < n) gcd_st.update(x, abs(T[x+1]-T[x]));
    } 
    else {
      ll l, r; cin >> l >> r;
      l--; r--;

      ll lo = min_st.query(l, r);
      ll hi = max_st.query(l, r);
      ll g = gcd_st.query(l, r-1);

      if (hi-lo == 0) cout << "YES\n";
      else if (dup_st.has_duplicate(l, r)) cout << "NO\n";
      else cout << ((g*(r-l) == (hi-lo)) ? "YES" : "NO") << "\n";
    }
  }

  return 0;
}