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

const ll INF = 1e18;

struct kick {
  ll x, y;
  int i;
  kick() : x(0), y(0), i(0) {}
};

struct segtree {
  int n;
  vector<ll> vals, deltas;
  segtree(vector<ll> &ar) {
    n = ar.size();
    vector<ll>(4*n, -INF).swap(vals);
    vector<ll>(4*n).swap(deltas);
    build(ar, 1, 0, n-1);
  }

  void build(vector<ll> &ar, int p, int i, int j) {
    if (i == j) {
      vals[p] = ar[i];
      return;
    }

    int k = (i+j)/2;
    build(ar, p<<1, i, k);
    build(ar, p<<1|1, k+1, j);
    pull(p);
  }

  void pull(int p) {
    vals[p] = max(vals[p<<1], vals[p<<1|1]); 
  }

  void push(int p, int i, int j) {
    if (deltas[p]) {
      vals[p] += deltas[p];
      if (i != j) {
        deltas[p<<1] += deltas[p];
        deltas[p<<1|1] += deltas[p];
      }
      deltas[p] = 0;
    }
  }

  void update(int _i, int _j, int p, ll v, int i, int j) {
    push(p, i, j);
    if (_i <= i && j <= _j) {
      deltas[p] += v;
      push(p, i, j);
    }
    else if (_j < i || j < _i) {

    }
    else {
      int k = (i+j)/2;
      update(_i, _j, p<<1, v, i, k);
      update(_i, _j, p<<1|1, v, k+1, j);
      pull(p);
    }
  }

  ll query(int _i, int _j, int p, int i, int j) {
    push(p, i, j);
    if (_i <= i && j <= _j) {
      return vals[p];
    }
    else if (_j < i || j < _i) {
      return 0;
    }
    else {
      int k = (i+j)/2;
      return max(query(_i, _j, p<<1, i, k),query(_i, _j, p<<1|1, k+1, j));
    }
  }
}; 

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, v; cin >> n >> v;
  vector<ll> t(n+1), a(n+1);
  vector<kick> ar(n+1);

  t[0] = a[0] = 0;
  for (int i = 1; i <= n; i++) cin >> t[i];
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 0; i <= n; i++) {
    ar[i].i = i;
    ar[i].x = -a[i]+t[i]*v;
    ar[i].y = a[i]+t[i]*v;
  }

  sort(ar.begin(), ar.end(), [](const kick &left, const kick &right) {
    return left.x < right.x;
  });
  for (int i = 0; i <= n; i++) ar[i].i = i;


  sort(ar.begin(), ar.end(), [](const kick &left, const kick &right) {
    return left.y < right.y;
  });
  vector<int> idx(n+1);
  for (int i = 0; i <= n; i++) {
    idx[ar[i].i] = i;
  }

  vector<ll> dp(n+1, -INF);
  segtree st(dp);

  for (int i = 0; i <= n; i++) {
    int j = idx[i];
    if (ar[j].x == ar[j].y && ar[j].x == 0) {
      st.update(j, j, 1, INF, 0, n);
      continue;
    }
    ll nv = st.query(0, j, 1, 0, n)+1;
    //cout << ar[j].x << " " << ar[j].y << " " << nv << endl;
    if (nv < 0) continue;
    st.update(j, j, 1, nv+INF, 0, n);
  }

  cout <<  st.query(0, n, 1, 0, n) << endl;
  
  return 0;
}