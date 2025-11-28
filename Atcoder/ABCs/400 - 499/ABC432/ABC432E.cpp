#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


template<typename T, T (*Op)(T&,T&), T id>
struct SegmentTree {
  int n; vector<T> st;
  SegmentTree(int _n) : n(_n), st(2*_n, id) {}
  void update(int p, T v) {
    for (st[p += n] = v; p >>= 1; )
      st[p] = Op(st[p<<1], st[p<<1|1]);
  }
  T query(int l, int r) {
    T resl = id, resr = id;
    for (l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
      if (l&1) resl = Op(resl, st[l++]);
      if (r&1) resr = Op(st[--r], resr);
    }
    return Op(resl, resr);
  }
  SegmentTree(vector<T> &ar) {
    n = ar.size(); st.assign(2*n, id);
    for (int i = 0; i < n; i++) st[i+n] = ar[i];
    for (int p = n-1; p > 0; p--)
      st[p] = Op(st[p<<1], st[p<<1|1]);
  }
};

struct S {
  int cnt; ll val;
};

S op(S &x, S &y) {
  return {x.cnt+y.cnt, x.val+y.val};
};

constexpr S id = {0,0};
typedef SegmentTree<S, op, id> ST;
const int MAXN = 5e5+5;


int main(){
  cin.tie(0)->sync_with_stdio(false);
  int n, q; cin >> n >> q;
  vector<int> a(n);
  for (int &x : a) cin >> x;

  vector<S> ar(MAXN);
  for (int i = 0; i < n; i++) {
    S cur = {1, a[i]};
    ar[a[i]] = op(ar[a[i]], cur);
  } 
  ST segtree(ar);
  
  // if l >= r, max(l, min(r, a_i)) = l for all i
  // if l < r, max(l, min(r, a_i)) = l if a_i <= l,
  //                                 a_i if l < a_i < r, 
  //                                 r if a_i >= r

  // count a_i <= l -> segtree, maintain freq table
  // sum a_i where l < a_i < r -> segtree, freq table but store values
  // count a_i >= r -> segtree, maintain freq table
  for (int i = 0; i < q; i++) {
    int t; ll x, y; cin >> t >> x >> y;
    if (t == 1) {
      x--;
      S cur_val = segtree.query(a[x], a[x]);
      segtree.update(a[x], {cur_val.cnt-1, cur_val.val-a[x]});

      a[x] = y;
      cur_val = segtree.query(a[x], a[x]);
      segtree.update(a[x], {cur_val.cnt+1, cur_val.val+a[x]});
    }
    else {
      ll result = 0;
      if (x < y) {
        S l_val = segtree.query(0, x);
        S r_val = segtree.query(y, MAXN-1);
        S mid_val = x+1 <= y-1 ? segtree.query(x+1, y-1) : id;
        
        result = l_val.cnt*x + r_val.cnt*y + mid_val.val;
      }
      else {
        result = x*n;
      }
      cout << result << "\n";
    }
  }

  return 0;
}
