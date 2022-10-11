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

#define int long long
const int N = 2e5+5;
const int LGN = 19;
const int INF = 1e9;
int par[LGN][N];
vi graph[N];
int subtree[N];

struct segtree {
  int n;
  vi vals, deltas;
  segtree(vi &ar) {
    n = ar.size();
    vi(4*n).swap(vals);
    vi(4*n).swap(deltas);
    build(ar, 1, 0, n-1);
  }
  void build(vi &ar, int p, int i, int j) {
    deltas[p] = 0;
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

  void update(int _i, int _j, int v, int p, int i, int j) {
    push(p, i, j);
    if (_i <= i && j <= _j) {
      deltas[p] += v;
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

  int query(int _i, int _j, int p, int i, int j) {
    push(p, i, j);
    if (_i <= i && j <= _j) {
      return vals[p];
    }
    else if (_j < i || j < _i) {
      return -INF;
    }
    else {
      int k = (i+j)/2;
      return max(query(_i, _j, p<<1, i, k),query(_i, _j, p<<1|1, k+1, j));
    }
  }

  int findmax(int p, int i, int j) {
    if (i == j) return i;
    push(p, i, j);
    int k = (i+j)/2;
    if (vals[p<<1] == vals[p]) return findmax(p<<1, i, k);
    else return findmax(p<<1|1, k+1, j);
  }
};

struct segtreemin {
  int n;
  vi vals, deltas;
  segtreemin(vi &ar) {
    n = ar.size();
    vi(4*n).swap(vals);
    vi(4*n).swap(deltas);
    build(ar, 1, 0, n-1);
  }
  void build(vi &ar, int p, int i, int j) {
    deltas[p] = 0;
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

  void update(int _i, int _j, int v, int p, int i, int j) {
    push(p, i, j);
    if (_i <= i && j <= _j) {
      deltas[p] += v;
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

  int query(int _i, int _j, int p, int i, int j) {
    push(p, i, j);
    if (_i <= i && j <= _j) {
      return vals[p];
    }
    else if (_j < i || j < _i) {
      return INF;
    }
    else {
      int k = (i+j)/2;
      return min(query(_i, _j, p<<1, i, k), query(_i, _j, p<<1|1, k+1, j));
    }
  }

};


void dfs(int u, int p, vi &ar, vi &dep) {
  ar.push_back(u);
  for (int v : graph[u]) {
    if (v == p) continue;
    dep[v] = dep[u]+1;
    dfs(v, u, ar, dep);
  }
}

void testcase() {
  int n, k; cin >> n >> k;
  for (int i = 1; i <= n; i++) graph[i].clear();

  par[0][1] = 1;
  for (int i = 2; i <= n; i++) {
    cin >> par[0][i];
    int v = par[0][i];
    int u = i;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  for (int kk = 1; kk < LGN; kk++) {
    for (int i = 1; i <= n; i++) {
      par[kk][i] = par[kk-1][par[kk-1][i]];
    }
  }

  
  vi ar, dep, star;
  dep.resize(n+1);
  map<int,int> idx;

  dep[1] = 0;
  dfs(1, -1, ar, dep);
  
  for (int i = 0; i < n; i++) {
    idx[ar[i]] = i;
    star.push_back(dep[ar[i]]);
  }
  /*
  for (int i = 0; i < n; i++) {
    cout << ar[i] << " " << star[i] << endl;
  }
  */

  segtree st(star);
  segtreemin stmin(star);

  
  while(k--) {
    int x = st.findmax(1, 0, n-1);
    int d = dep[ar[x]];
    if (d == 1) break;
    int up = d/2;

    int l = ar[x];

    for(int kk = LGN-1; kk >= 0; kk--) {
      if (dep[par[kk][l]] <= up) continue;
      l = par[kk][l];
    }
    //cout << up << " " << d << " " << l << endl;
    l = idx[l];
    
    int lo = l+1;
    int hi = n-1;
    int r = l;
    while(lo <= hi) {
      int mid = hi-(hi-lo)/2;
      if (stmin.query(l+1, mid, 1, 0, n-1) > dep[ar[l]]) {
        r = mid;
        lo = mid+1;
      }
      else hi = mid-1;
    }
    //cout << l << " " << r << endl;
    st.update(l, r, -up, 1, 0, n-1);
    stmin.update(l, r, -up, 1, 0, n-1);
  }
  cout << st.query(0, n-1, 1, 0, n-1) << "\n";
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--) testcase();
  
  return 0;
}
