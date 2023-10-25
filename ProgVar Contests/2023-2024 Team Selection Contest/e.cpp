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

struct operation {
  int t; // 0 = query, 1 = update
  ll l, r, v;

  // update
  operation(ll l, ll r, ll v) : t(1), l(l), r(r), v(v) {}

  // query
  operation(ll l, ll r) : t(0), l(l), r(r), v(0) {}
};

struct CompressedST {
  int n;
  vector<ll> st, lazy;

  // compressed information
  vector<pair<ll,ll>> lr;
  map<ll, int> compress;
  CompressedST(vector<ll> &c) {
    int sz = c.size();
    for (int i = 0; i < sz-1; i++) {
      compress[c[i]] = lr.size();
      lr.push_back({c[i], c[i]});
      if (c[i]+1 <= c[i+1]-1) 
        lr.push_back({c[i]+1, c[i+1]-1});
    }
    compress[c[sz-1]] = lr.size();
    lr.push_back({c[sz-1], c[sz-1]});
    n = lr.size();
  
    st.assign(4*n, 0);
    lazy.assign(4*n, 0);
  } 

  void pull(int p) {
    st[p] = st[p<<1] + st[p<<1|1];
  }

  void push(int p, int i, int j) {
    if (lazy[p]) {
      st[p] += (lr[j].second-lr[i].first+1)*lazy[p];
      if (i != j) {
        lazy[p<<1] += lazy[p];
        lazy[p<<1|1] += lazy[p];
      }
      lazy[p] = 0;
    }
  }

  void update(int l, int r, ll v, int p, int i, int j) {
    push(p, i, j);
    if (l <= i && j <= r) {
      lazy[p] += v;
      push(p, i, j);
    }
    else if (j < l || r < i);
    else {
      int k = (i+j)/2;
      update(l, r, v, p<<1, i, k);
      update(l, r, v, p<<1|1, k+1, j);
      pull(p);
    }
  }

  ll query(int l, int r, int p, int i, int j) {
    push(p, i, j);
    if (l <= i && j <= r) return st[p];
    else if (j < l || r < i) return 0;
    else {
      int k = (i+j)/2;
      return query(l, r, p<<1, i, k) 
        + query(l, r, p<<1|1, k+1, j);
    }
  }

  ll query(ll l, ll r) {
    return query(compress[l], compress[r], 1, 0, n-1);
  } 
  void update(ll l, ll r, ll v) {
    update(compress[l], compress[r], v, 1, 0, n-1);
  }
};

const ll INF = 1e18;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, m, L; cin >> n >> m >> L;
  vector<ll> f(n), c(m);
  for (int i = 0; i < n; i++) cin >> f[i];
  for (int i = 0; i < m; i++) cin >> c[i];

  // simulate queries and updates
  vector<operation> ops;
  ops.push_back(operation(0, L-1, 1));

  ll loose = L; 
  for (int i = 0; i < n; i++) {
    if (i%2 == 0) {
      ops.push_back(operation(loose-f[i], loose-1, -1));
      ops.push_back(operation(loose-2*f[i], loose-f[i]-1, 1));
      loose = loose-2*f[i];
    }
    else {
      ops.push_back(operation(loose, loose+f[i]-1, -1));
      ops.push_back(operation(loose+f[i], loose+2*f[i]-1, 1));
      loose = loose+2*f[i];
    }
  }

  ll currL = -INF;
  for (int i = 0; i < m; i++) {
    ll currR = c[i];
    ops.push_back(operation(currL, currR-1));
    currL = c[i];
  }  
  ops.push_back(operation(currL, INF));


  // compress coordinates
  vector<ll> coords_tmp;
  for (operation op : ops) {
    coords_tmp.push_back(op.l);
    coords_tmp.push_back(op.r);
  }
  sort(coords_tmp.begin(), coords_tmp.end());

  vector<ll> coords;
  coords.push_back(coords_tmp[0]);
  for (int i = 1; i < coords_tmp.size(); i++)
    if (coords_tmp[i] == coords_tmp[i-1]) continue;
    else coords.push_back(coords_tmp[i]);
  
  // solve
  CompressedST st(coords);
  vector<ll> answers;
  for (operation op : ops) {
    if (op.t == 0) answers.push_back(st.query(op.l, op.r));
    else st.update(op.l, op.r, op.v);
  }

  for (int i = 0; i < m+1; i++) {
    cout << answers[i];
    if (i+1 < m+1) cout << " ";
    else cout << "\n";
  }

  return 0;
}
