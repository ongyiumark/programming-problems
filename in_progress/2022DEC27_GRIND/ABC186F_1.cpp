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

struct segtree {
  int n;
  vector<ll> vals, deltas;

  segtree(int _n, vector<ll> &ar) {
    n = _n;
    vector<ll>(4*n).swap(vals);
    vector<ll>(4*n).swap(deltas);

    build(ar, 1, 0, n-1);
  }

  void pull(int p) {
    vals[p] = vals[p<<1] + vals[p<<1|1];
  }

  void build(vector<ll> &ar, int p, int i, int j) {
    if (i == j) {
      vals[p] = ar[i];
    }
    else {
      int k = (i+j)/2;
      build(ar, p<<1, i, k);
      build(ar, p<<1|1, k+1, j);
      pull(p);
    }
  }

  void push(int p, int i, int j) {
    if (deltas[p]) {
      vals[p] += deltas[p]*(j-i+1);
      if (i != j) {
        deltas[p<<1] += deltas[p];
        deltas[p<<1|1] += deltas[p];
      }
      deltas[p] = 0;
    }
  }

  void update(int l, int r, int v, int p, int i, int j) {
    push(p, i, j);
    if (l <= i && j <= r) {
      deltas[p] += v;
      push(p, i, j);
    }
    else if (j < l || r < i) {

    }
    else {
      int k = (i+j)/2;
      update(l, r, v, p<<1, i, k);
      update(l, r, v, p<<1|1, k+1, j);
      pull(p);
    }
  }

  ll query(int l, int r, int p, int i, int j) {
    push(p, i, j);
    if (l <= i && j <= r) {
      return vals[p];
    }
    else if (j < l || r < i) {
      return 0;
    }
    else {
      int k = (i+j)/2;
      return query(l, r, p<<1, i, k) + query(l, r, p<<1|1, k+1, j);
    }
  }

  ll query(int l, int r) {
    return query(l, r, 1, 0, n-1);
  }

  void set(int l, int v) {
    update(l, l, v-query(l, l), 1, 0, n-1);
  }

};

const int N = 2e5+5;
vector<ll> obsX[N], obsY[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll h, w, m;
  cin >> h >> w >> m;

  for (int i = 0; i < m; i++) {
    ll x, y; cin >> x >> y;
    obsX[x].push_back(y);
    obsY[y].push_back(x);
  }

  for (int i = 1; i <= h; i++) obsX[i].push_back(w+1), sort(obsX[i].begin(), obsX[i].end());
  for (int j = 1; j <= w; j++) obsY[j].push_back(h+1), sort(obsY[j].begin(), obsY[j].end());

  ll ans = 0;
  for (int i = 1; i <= h && obsX[i][0] > 1; i++) ans += obsX[i][0]-1;

  vector<ll> ar(h+5);
  segtree st(h+5, ar);

  for (int j = 1; j <= w && obsY[j][0] > 1; j++) {
    ans += st.query(1, min(obsY[j][0], obsY[1][0])-1) + max(0LL, obsY[j][0] - obsY[1][0]);
    for (ll &x : obsY[j]) st.set(x, 1);
  }

  cout << ans << "\n";

  return 0;
}
