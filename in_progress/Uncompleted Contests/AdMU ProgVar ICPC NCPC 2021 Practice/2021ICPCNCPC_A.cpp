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

const ll INF = 1e18;
struct minsegtree {
  int n;
  ll *vals, *deltas;
  minsegtree(int n) : n(n) {
    vals = new ll[4*n];
    deltas = new ll[4*n];
    build(1, 0, n-1);
  }

  void build(int p, int i, int j) {
    deltas[p] = 0;
    if (i == j) vals[p] = INF;
    else {
      int k = (i+j)/2;
      build(p<<1, i, k);
      build(p<<1|1, k+1, j);
      pull(p);
    }
  }

  void pull(int p) {
    vals[p] = min(vals[p<<1], vals[p<<1|1]);
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

  void update(int _i, int _j, ll v, int p, int i, int j) {
    push(p,i,j);
    if (_i <= i && j <= _j) {
      deltas[p] += v;
      push(p, i, j);
    }
    else if (j < _i || _j < i) {

    }
    else {
      int k = (i+j)/2;
      update(_i, _j, v, p<<1, i , k);
      update(_i, _j, v, p<<1|1, k+1, j);
      pull(p);
    }
  }

  ll query(int _i, int _j, int p, int i, int j) {
    push(p,i,j);
    if (_i <= i && j <= _j) {
      return vals[p];
    }
    else if (j < _i || _j < i) {
      return INF;
    }
    else {
      int k = (i+j)/2;
      return min(query(_i, _j, p<<1, i , k),query(_i, _j, p<<1|1, k+1, j));
    }
  }
};

struct maxsegtree {
  int n;
  ll *vals, *deltas;
  maxsegtree(int n) : n(n) {
    vals = new ll[4*n];
    deltas = new ll[4*n];
    build(1, 0, n-1);
  }

  void build(int p, int i, int j) {
    deltas[p] = 0;
    if (i == j) vals[p] = -INF;
    else {
      int k = (i+j)/2;
      build(p<<1, i, k);
      build(p<<1|1, k+1, j);
      pull(p);
    }
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

  void update(int _i, int _j, ll v, int p, int i, int j) {
    push(p,i,j);
    if (_i <= i && j <= _j) {
      deltas[p] += v;
      push(p, i, j);
    }
    else if (j < _i || _j < i) {

    }
    else {
      int k = (i+j)/2;
      update(_i, _j, v, p<<1, i , k);
      update(_i, _j, v, p<<1|1, k+1, j);
      pull(p);
    }
  }

  ll query(int _i, int _j, int p, int i, int j) {
    push(p,i,j);
    if (_i <= i && j <= _j) {
      return vals[p];
    }
    else if (j < _i || _j < i) {
      return -INF;
    }
    else {
      int k = (i+j)/2;
      return max(query(_i, _j, p<<1, i , k),query(_i, _j, p<<1|1, k+1, j));
    }
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll n, c; cin >> n >> c; 
  minsegtree minst(n);
  maxsegtree maxst(n);
  for (int i = 0; i < n; i++) {
    ll x; cin >> x;
    
    if (i > 0) {
      maxst.update(0, i-1, -c, 1, 0, n-1);
      minst.update(0, i-1, +c, 1, 0, n-1);
    }
    maxst.update(i,i, INF+x, 1, 0, n-1);
    minst.update(i,i, -INF+x, 1, 0, n-1);
  
    cout << max(maxst.query(0, i, 1, 0, n-1)-x, x-minst.query(0, i, 1, 0, n-1));
  
    if (i < n-1) cout << " ";
    else cout << endl;
  }
  return 0;
}
