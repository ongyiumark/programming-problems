#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


template<typename T, T (*Op)(T,T), T Identity>
struct SegmentTree {
  vector<T> st; int n;
  SegmentTree(int n) : n(n) {
    st.assign(2*n, Identity);
  }
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

ll ADD_OP(ll a, ll b) { return a+b; }

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int case_no = 0;
  while (true) {
    int n; cin >> n;
    case_no++;
    if (n == 0) break;
    if (case_no > 1) cout << "\n";
    cout << "Case " << case_no << ":\n";

    vector<int> ar(n);
    for (int &x : ar) cin >> x;
    SegmentTree<ll, ADD_OP, 0> st(n);
    for (int i = 0; i < n; i++) st.update(i, ar[i]);
    while (true) {
      string op; cin >> op;
      if (op == "END") break;

      if (op == "S") {
        int x, r; cin >> x >> r;
        st.update(x-1, r);
      }
      else {
        int x, y; cin >> x >> y;
        cout << st.query(x-1,y-1) << "\n";
      }
    }
  }
}