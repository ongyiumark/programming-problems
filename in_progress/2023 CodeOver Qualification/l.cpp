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
  vector<int> vals;
  vector<int> deltas;

  segtree(vector<int> &ar) {
    int n = ar.size();
    vector<int>(4*n).swap(vals);
    vector<int>(4*n).swap(deltas);

    build(ar, 1, 0, n-1);
  }

  void build(vector<int> &ar, int p, int i, int j) {
    if (i == j) {
      vals[p] = ar[i];
      return;
    }

    int k = (i+j)>>1;
    build(ar, p<<1, i, k);
    build(ar, p<<1|1, k+1, j);
    pull(p);
  }

  void pull(int p) {
    vals[p] = max(vals[p<<1], vals[p<<1|1]);
  }

  void push(int p, int i, int j) {
    if (deltas[p] != 0) {
      vals[p] += deltas[p];
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
    else if (j < l || r < i) {}
    else {
      int k = (i+j)>>1;
      update(l, r, v, p<<1, i, k);
      update(l, r, v, p<<1|1, k+1, j);
      pull(p);
    }
  }

  int query(int l, int r, int p, int i, int j) {
    if (l <= i && j <= r) {
      return vals[p];
    } 
    else if (j < l || r < i) { return -100; }
    else {
      int k = (i+j)>>1;
      return max(query(l, r, p<<1, i, k), query(l, r, p<<1|1, k+1, j));
    }
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  vector<int> A(n);
  for (int &x : A) cin >> x;
  segtree st(A);

  vector<vector<int>> ans;

  while(st.query(0, n-1, 1, 0, n-1) >= 0) {
    vector<int> tmp;
    // find first
    int lo = 0;
    int hi = n-1;
    int start = 0;
    while (lo <= hi) {
      int mid = hi-(hi-lo)/2;
      if (st.query(0, mid, 1, 0, n-1) >= 0) {
        start = mid;
        hi = mid-1;
      }
      else lo = mid+1;
    }
    tmp.push_back(start);

    // remove
    st.update(start, start, -A[start]-1, 1, 0, n-1);

    while(tmp.back()+1 < n && st.query(tmp.back()+1, n-1, 1, 0, n-1) > A[tmp.back()]) {
      lo = tmp.back();
      hi = n-1;
      int nxt = lo;

      while(lo <= hi) {
        int mid = hi-(hi-lo)/2;
        if (st.query(tmp.back()+1, mid, 1, 0, n-1) > A[tmp.back()]) {
          nxt = mid;
          hi = mid-1;
        }
        else lo = mid+1;
      }

      tmp.push_back(nxt);
      // remove
      st.update(nxt, nxt, -A[nxt]-1, 1, 0, n-1);
    }

    ans.push_back(tmp);
  }

  cout << ans.size() << endl;
  for (vector<int> &tmp : ans) {
    int sz = tmp.size();
    for (int i = 0; i < sz; i++) {
      cout << A[tmp[i]];
      if (i + 1 < sz) cout << " ";
      else cout << "\n";
    }
   }


 
  return 0;
}
