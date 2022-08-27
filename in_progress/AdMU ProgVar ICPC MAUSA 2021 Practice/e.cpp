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
int pref[N][6];
int mask[N];

struct node {
  int *arr;
  node() {
    arr = new int[64];
    memset(arr, 0, sizeof arr);
  }

  void reset() {
    memset(arr, 0, sizeof arr);
  }

  ll solve() {
    ll total = 0;
    for (int i = 0; i < 64; i++) {
      total += (ll)arr[i]*(arr[i]-1)/2;
    }
    return total;
  }

  void operator+=(const node &other) const {
    for (int i = 0; i < 64; i++) arr[i] += other.arr[i];
  }
};

node operator+(const node &left, const node &right) {
  node res;
  for (int i = 0; i < 64; i++) res.arr[i] = left.arr[i]+right.arr[i];
  return res;
}

struct segtree {
  int n;
  int *lo, *hi;
  node *vals;
  int *deltas;

  segtree(vector<node> &ar) {
    n = ar.size();
    lo = new int[4*n+1];
    hi = new int[4*n+1];
    vals = new node[4*n+1];
    deltas = new int[4*n+1];
    init(ar, 1, 0, n-1);
  }

  void init(vector<node> &ar, int i, int l, int r) {
    lo[i] = l; hi[i] = r;
    deltas[i] = 0;
    if (l == r) {
      vals[i] = ar[l];
      return;
    }
    
    int k = (l+r)/2;
    init(ar, 2*i, l, k);
    init(ar, 2*i+1, k+1, r);

    pull(i);
  }

  void push(int i) {
    deltas[2*i] ^= deltas[i];
    deltas[2*i+1] ^= deltas[i];
    deltas[i] = 0;
  }

  void pull(int i) {
    node left, right;

    for (int j = 0; j < 64; j++) {
      left.arr[j^deltas[2*i]] = vals[2*i].arr[j];
      right.arr[j^deltas[2*i+1]] = vals[2*i+1].arr[j];
    }

    vals[i] = left+right;
  }

  void update(int i, int l, int r, int mask) {
    if (r < lo[i] || hi[i] < l) return;
    if (l <= lo[i] && hi[i] <= r) {
      deltas[i] ^= mask;
      return;
    }

    push(i);
    update(2*i, l, r, mask);
    update(2*i+1, l, r, mask);

    pull(i);
  }

  node query(int i, int l, int r) {
    node tmp;
    if (r < lo[i] || hi[i] < l) return tmp;
    if (l <= lo[i] && hi[i] <= r) {
      for (int j = 0; j < 64; j++) {
        tmp.arr[j^deltas[i]] = vals[i].arr[j];
      }
      return tmp;
    }

    push(i);
    tmp = query(2*i, l, r)+query(2*i+1, l, r);
    pull(i);
    
    return tmp;
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s; cin >> s;
  int n = s.size();

  // Prefix sums
  memset(pref, 0, sizeof pref);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < 6; j++) {
      pref[i+1][j] = pref[i][j];
    }
    pref[i+1][s[i]-'a']++;
  }

  // Mask where jth bit indicates that the jth letter is odd
  memset(mask, 0, sizeof mask);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 6; j++) {
      mask[i] |= (pref[i][j]%2)*(1<<j);
    }
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
      ll cnt = st.query(1, l-1, r).solve();
      cout << cnt << endl;
    }
    else {
      int i; char x; cin >> i >> x;
      int mask = 0;
      mask |= (1<<(s[i-1]-'a'));
      mask |= (1<<(x-'a'));
      //cout << "MASK: " << mask << endl;
      st.update(1, i, n, mask);
    }
  }
  
  return 0;
}
