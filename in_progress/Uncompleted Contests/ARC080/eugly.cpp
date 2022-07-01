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

const int INF = 1e9;
const int N = 2e5+5;
int p[N];
int to_idx[N];

struct node {
  int a, b;

  node(int a=INF, int b=INF) : a(a), b(b) {}

  bool exists() {
    return (a != INF || b != INF); 
  }
};

node comb(const node& left, const node& right){
  return node(min(left.a, right.a), min(left.b, right.b));
}

node minL(node left, node right) {
  if (left.a < right.a) return left;
  else return right;
}

node minR(node left, node right) {
  if (left.b < right.b) return left;
  else return right;
}

node flip_node(const node& x){
  return node(x.b, x.a);
}

struct segtree {
  int n;
  node *vals, *deltas;
  bool *flag;

  segtree(vector<node> &ar) {
    n = ar.size();
    vals = new node[4*n];
    deltas = new node[4*n];
    flag = new bool[4*n];
    build(ar,1,0,n-1);
  }

  void build(vector<node> &ar, int p, int i, int j) {
    deltas[p] = node();
    flag[p] = 0;
    if (i == j) vals[p] = ar[i];
    else {
      int k = (i+j)/2;
      build(ar, p << 1, i, k);
      build(ar, p << 1|1, k+1, j);
      pull(p);
    }
  }

  void pull(int p) {
    vals[p] = comb(vals[p<<1], vals[p<<1|1]);
  }

  void push(int p, int i, int j) {
    if (deltas[p].exists()) {
      vals[p] = deltas[p];
      if (i != j) {
        deltas[p<<1] = deltas[p];
        deltas[p<<1|1] = deltas[p];
      }
      deltas[p] = node();
    }
    if (flag[p]) {
      vals[p] = flip_node(vals[p]);
      if (i != j) {
        flag[p<<1] = !flag[p<<1];
        flag[p<<1|1] = !flag[p<<1|1];
      }
      flag[p] = 0;
    }
  }

  void update(int _i, int _j, node v, int p, int i, int j) {
    push(p, i, j);
    if (_i <= i && j <= _j) {
      deltas[p] = v;
      push(p, i, j);
    }
    else if (_j < i || j < _i) {}
    else {
      int k = (i+j)/2;
      update(_i, _j, v, p<<1, i, k);
      update(_i, _j, v, p<<1|1, k+1, j);
      pull(p);
    }
  }

  void flip(int _i, int _j, int p, int i, int j) {
    push(p, i, j);
    if (_i <= i && j <= _j) {
      flag[p] = !flag[p];
      push(p, i, j);
    }
    else if (_j < i || j < _i) {}
    else {
      int k = (i+j)/2;
      flip(_i, _j, p<<1, i, k);
      flip(_i, _j, p<<1|1, k+1, j);
      pull(p);
    }
  }

  node queryL(int _i, int _j, int p, int i, int j) {
    push(p, i, j);
    if (_i <= i && j <= _j) return vals[p];
    else if (_j < i || j < _i) return node();

    int k = (i+j)/2;
    return minL(queryL(_i, _j, p<<1, i, k), queryL(_i, _j, p<<1|1, k+1,j));
  }

  node queryR(int _i, int _j, int p, int i, int j) {
    push(p, i, j);
    if (_i <= i && j <= _j) return vals[p];
    else if (_j < i || j < _i) return node();

    int k = (i+j)/2;
    return minR(queryR(_i, _j, p<<1, i, k), queryR(_i, _j, p<<1|1, k+1,j));
  }
};

int n;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    to_idx[p[i]] = i;
  }

  vector<node> ar;
  for (int i = 0; i < n; i++){
    int l = (i%2 ? INF : p[i]);
    int r = (i%2 ? p[i] : INF);
    ar.push_back(node(l, r));
  }
  
  segtree st(ar);
  vector<int> ans;
  set<int> se;
  se.insert(-1); se.insert(n);

  for (int i = 0; i < n/2; i++) {
    node l = st.queryL(0, n-1, 1, 0, n-1);
    int idxl = to_idx[l.a];

    int lend = *se.lower_bound(idxl);

    node r = st.queryR(idxl, lend, 1, 0, n-1);
    int idxr = to_idx[r.b];

    se.insert(idxl); se.insert(idxr);
    ans.push_back(l.a);
    ans.push_back(r.b);

    st.update(idxl, idxl, node(n+1,INF), 1, 0, n-1);
    st.update(idxr, idxr, node(INF,n+1), 1, 0, n-1);

    if (idxl+1 < idxr-1) st.flip(idxl+1, idxr-1, 1, 0, n-1);
  }

  int sz = ans.size();
  for (int i = 0; i < sz; i++) {
    cout << ans[i];
    if (i != sz-1) cout << " ";
    else cout << endl;
  }
  
  return 0;
  
  
}
