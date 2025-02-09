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
  vi vals;
  int n;

  segtree(vi &ar) {
    n = ar.size();
    vector<int>(4*n).swap(vals);

    build(ar, 1, 0, n-1);
  }

  void build(vi &ar, int p, int i, int j) {
    if (i == j){
      vals[p] = ar[i];
      return;
    }

    int k = (i+j)/2;
    build(ar, p<<1, i, k);
    build(ar, p<<1|1, k+1, j);
    pull(p);
  }

  void pull(int p){
    vals[p] = vals[p<<1]^vals[p<<1|1];
  }


  void update(int l, int p, int v, int i, int j) {
    if (l <= i && j <= l) {
      vals[p] ^= v;
    }
    else if (j < l || l < i) {

    }
    else {
      int k = (i+j)/2;
      update(l, p<<1, v, i, k);
      update(l, p<<1|1, v, k+1, j);
      pull(p);
    }
  }

  int query(int l, int r, int p, int i, int j) {
    if (l <= i && j <= r) {
      return vals[p];
    }
    else if (j < l || r < i) {
      return 0;
    } 
    else {
      int k = (i+j)/2;
      return query(l, r, p<<1, i, k)^query(l, r, p<<1|1, k+1, j);
    }
  }
};

vector<int> ar;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, q; cin >> n >> q;
  ar.resize(n);

  for (int i = 0; i < n; i++) cin >> ar[i];
  segtree st(ar);

  while(q--) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      x--;
      st.update(x, 1, y, 0, n-1);
    }
    else {
      x--; y--;
      cout << st.query(x, y, 1, 0, n-1) << "\n";
    }
  }

  return 0;
}
