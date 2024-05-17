#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

struct SegmentTree {
  static inline int Identity = -1e9;

  int n;
  vector<int> st, lazy;
  vector<set<int>> persist;
  SegmentTree(int n) : n(n), st(4*n, Identity), lazy(4*n, Identity), persist(4*n) {}
  void propagate(int p) {
    int val = (persist[p].size() ? *persist[p].rbegin() : Identity);
    lazy[p<<1] = max(val, lazy[p]);
    lazy[p<<1|1] = max(val, lazy[p]);
  }
  void pull(int p, int i, int j) {
    int val = (persist[p].size() ? *persist[p].rbegin() : Identity);
    int left = (i != j ? st[p<<1] : Identity);
    int right = (i != j ? st[p<<1|1] : Identity);
    st[p] = max({val, left, right});
  }
  
  void update(int l, int r, int v) { update(l, r, v, 1, 0, n-1); }
  void update(int l, int r, int v, int p, int i, int j) {
    if (l <= i && j <= r) {
      persist[p].insert(v);
    }
    else if (j < l || r < i);
    else {
      int k = (i+j)/2;
      update(l, r, v, p<<1, i, k);
      update(l, r, v, p<<1|1, k+1, j);
    }
    pull(p, i, j);
  }

  void erase(int l, int r, int v) { erase(l, r, v, 1, 0, n-1); }
  void erase(int l, int r, int v, int p, int i, int j) {
    if (l <= i && j <= r) {
      persist[p].erase(v);
    }
    else if (j < l || r < i);
    else {
      int k = (i+j)/2;
      erase(l, r, v, p<<1, i, k);
      erase(l, r, v, p<<1|1, k+1, j);
    }
    pull(p, i, j);
  }

  int query(int l, int r) { return query(l, r, 1, 0, n-1); }
  int query(int l, int r, int p, int i, int j) {
    if (l <= i && j <= r) {
      return max(st[p], lazy[p]);
    }
    else if (j < l || r < i) return Identity;
    else {
      int k = (i+j)/2;
      propagate(p);
      int left = query(l, r, p<<1, i, k);
      int right = query(l, r, p<<1|1, k+1, j);
      lazy[p<<1] = lazy[p<<1|1] = Identity;
      return max(left, right);
    }
  }

};
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, e; cin >> n >> e;
  vector<string> names(e);
  vector<ii> newcomer(e);
  SegmentTree st(n);
  for (int i = 0; i < e; i++) {
    int op; cin >> op;
    if (op == 1) {
      int a, b; string name;
      cin >> name >> a >> b;
      newcomer[i] = {a, b};
      names[i] = name;
      st.update(a, b, i);
    }
    else {
      int c, d; cin >> c >> d;
      int j = st.query(c, d);
      if (j == SegmentTree::Identity) cout << ">_<\n";
      else {
        cout << names[j] << "\n";
        auto [a, b] = newcomer[j];
        st.erase(a, b, j);
      }
    }
  }


  return 0;
}