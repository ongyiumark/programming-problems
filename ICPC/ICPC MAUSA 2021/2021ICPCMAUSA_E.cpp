#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5+5;
int mask[N];

struct node {
  vector<int> arr;
  node() {
    reset();
  }

  void reset() {
    vector<int>(64).swap(arr);
  }

  ll solve() {
    ll total = 0;
    for (int i = 0; i < 64; i++) {
      total += (ll)arr[i]*(arr[i]-1)/2;
    }
    return total;
  }

  int show() {
    int cnt = 0;
    for (int i = 0; i < 64; i++) {
      if (arr[i]) cnt++;
    }
    assert(cnt == 1);
    for (int i = 0; i < 64; i++) {
      if (arr[i]) {
        assert(arr[i] == 1);
        return i;
      }
    }
    return -1;
  }

  void operator+=(const node &other) {
    for (int i = 0; i < 64; i++) arr[i] += other.arr[i];
  }

  node operator+(const node &other) const {
    node res;
    for (int i = 0; i < 64; i++) res.arr[i] = arr[i]+other.arr[i];
    return res;
  }
};

const node ZERO;

struct segtree {
  int n;
  vector<node> vals;
  vector<int> deltas;

  segtree(vector<node> &ar) {
    n = ar.size();
    vector<node>(4*n).swap(vals);
    vector<int>(4*n).swap(deltas);
    build(ar, 1, 0, n-1);
  }

  void build(vector<node> &ar, int p, int i, int j) {
    deltas[i] = 0;
    if (i == j) {
      vals[p] = ar[i];
      return;
    }
    
    int k = (i+j)/2;
    build(ar, p<<1, i, k);
    build(ar, p<<1|1, k+1, j);

    pull(p);
  }

  void push(int p, int i, int j) {
    if (deltas[p]) {
      node tmp;
      for (int k = 0; k < 64; k++) {
        tmp.arr[k^deltas[p]] = vals[p].arr[k];
      }
      vals[p] = tmp;
      
      if (i != j) {
        deltas[p<<1] ^= deltas[p];
        deltas[p<<1|1] ^= deltas[p];
      }
      deltas[p] = 0;
    }
  }

  void pull(int p) {
    vals[p] = vals[p<<1] + vals[p<<1|1];
  }

  void update(int _i, int _j, int v, int p, int i, int j) {
    push(p, i, j);
    
    if (_i <= i && j <= _j) {
      deltas[p] ^= v;
      push(p, i, j);
    }
    else if (_j < i || j < _i) {

    }
    else {
      int k = (i+j)/2;
      update(_i, _j, v, p<<1, i, k);
      update(_i, _j, v, p<<1|1, k+1, j);
      pull(p);
    }
  }

  node query(int _i, int _j, int p, int i, int j) {
    push(p, i, j);
    if (_i <= i && j <= _j) {
      return vals[p];
    }
    else if (_j < i || j < _i) {
      return ZERO;
    }
    else {
      int k = (i+j)/2;
      return query(_i, _j, p<<1, i, k) + query(_i, _j, p<<1|1, k+1, j);
    }
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s; cin >> s;
  int n = s.size();

  // Mask where jth bit indicates that the jth letter is odd
  memset(mask, 0, sizeof mask);
  for (int i = 0; i < n; i++) {
    mask[i+1] = mask[i]^(1<<(s[i]-'a'));
  }

  vector<node> ar(n+1);
  for (int i = 0; i <= n; i++) {
    ar[i].arr[mask[i]] = 1;
  }
  segtree st(ar);
  
  int q; cin >> q;
  while(q--) {
    int t; cin >> t;
    if (t == 1) {
      int l, r; cin >> l >> r;
      ll cnt = st.query(l-1, r, 1, 0, n).solve();
      cout << cnt << endl;
    }
    else {
      int i; char x; cin >> i >> x;
      int mask = 0;
      mask ^= (1<<(s[i-1]-'a'));
      mask ^= (1<<(x-'a'));
      s[i-1] = x;
      st.update(i, n, mask, 1, 0, n);
    }
  }
  
  return 0;
}
