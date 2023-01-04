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

const int N = 3e5+5;
struct souv {
  int l, r;
};

bool operator<(const souv &left, const souv& right) {
  return left.r-left.l+1 < right.r - right.l + 1;
}

vector<souv> s;
vector<int> ans;

void add_range(int l, int r, int v) {
  ans[l] += v;
  ans[r+1] -= v;
}

struct segtree {
  int n;
  vi vals, deltas;

  segtree(int _n, vi &ar) {
    n = _n;
    vi(4*n).swap(vals);
    vi(4*n).swap(deltas);
    build(ar, 0, n-1, 1);
  }

  void pull(int p) {
    vals[p] = vals[p<<1] + vals[p<<1|1];
  }

  void build(vi &ar, int l, int r, int p) {
    if (l == r) {
      vals[p] = ar[l];
      return;
    }

    int k = (l+r)/2;
    build(ar, l, k, p<<1);
    build(ar, k+1,r, p<<1|1);
    pull(p);
  }

  void push(int l, int r, int p) {
    vals[p] += (r-l+1)*deltas[p];
    if (l != r) {
      deltas[p<<1] += deltas[p];
      deltas[p<<1|1] += deltas[p];
    }
    deltas[p] = 0;
  }

  void update(int i, int j, int v, int p, int l, int r) {
    push(l, r, p);
    if (i <= l && r <= j) {
      deltas[p] += v;
      push(l, r, p);
    }
    else if (r < i || j < l) {

    }
    else {
      int k = (l+r)/2;
      update(i, j, v, p<<1, l, k);
      update(i, j, v, p<<1|1, k+1, r);
      pull(p);
    }
  }

  int query(int i, int j, int p, int l, int r) {
    push(l, r, p);
    if (i <= l && r <= j) {
      return vals[p];
    }
    else if (r < i || j < l) {
      return 0;
    }
    else {
      int k = (l+r)/2;
      return query(i, j, p<<1, l, k) + query(i, j, p<<1|1, k+1, r);
    }
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, m; cin >> n >> m;
  s.resize(n);
  for (int i = 0; i < n; i++) {
    int l, r; cin >> l >> r;
    s[i] = {l, r};
  }

  ans.resize(m+5);
  for (int i = 0; i <= m; i++) ans[i] = 0;
  for (int i = 0; i < n; i++) {
    add_range(1, s[i].r - s[i].l + 1, 1);
  }

  sort(s.begin(), s.end());
  
  vi ar(m+1);
  segtree st(m+1, ar);

  int i, j, k;
  for (i = 1, j = 0, k = 0; i <= m; i++){
    while (j < n && s[j].r - s[j].l + 1 < i) j++;
    while(k < j) {
      st.update(s[k].l, s[k].r, 1, 1, 0, m);
      k++;
    }

    for (int l = i; l <= m; l += i) {
      int v = st.query(l, l, 1, 0, m);
      add_range(i, i, v);
    }
  }

  for (int i = 1; i <= m; i++) {
    ans[i] += ans[i-1]; 
  }

  for (int i = 1; i <= m; i++) {
    cout << ans[i] << "\n";
  }

  return 0;
}
