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

const int N = 1e5+5;
const ll INF = 1e18;
vector<ll> a(N);

struct segtree {
  int n;
  vector<ll> vals;
  segtree(vector<ll> &ar) {
    n = ar.size();
    vector<ll>(4*n, INF).swap(vals);
    build(ar, 1, 0, n-1);
  } 

  void build(vector<ll> &ar, int p, int i, int j) {
    vals[p] = INF;
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
    vals[p] = min(vals[p<<1],vals[p<<1|1]);
  }

  ll query(int l, int r) {
    return query(l, r, 1, 0, n-1);
  }
  ll query(int _i, int _j, int p, int i, int j) { 
    if (_i <= i && j <= _j) return vals[p];
    else if (j < _i || _j < i) return INF;
    int k = (i+j)/2;
    return min(query(_i, _j, p<<1, i, k), query(_i,_j, p<<1|1, k+1, j));
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  segtree st(a);

  ll ans = -INF;
  int lbest, rbest;
  for (int i = 0; i < n; i++) {
    int lo = 0;
    int hi = i;
    int lans = -1;
    while(lo <= hi) {
      int mid = hi-(hi-lo)/2;
      if (st.query(mid,i) >= a[i]) {
        lans = mid;
        hi = mid-1;
      }
      else lo = mid+1;
    }

    lo = i;
    hi = n-1;
    int rans = -1;
    while(lo <= hi) {
      int mid = hi-(hi-lo)/2;
      if (st.query(i,mid) >= a[i]) {
        rans = mid;
        lo = mid+1;
      }
      else hi = mid-1;
    }

    ll tmp = (rans-lans+1)*a[i];
    if (ans <= tmp) {
      if (ans == tmp) {
        if (lans < lbest) {
          lbest = lans;
          rbest = rans;
        }
      }
      else {
        ans = tmp;
        lbest = lans;
        rbest = rans;
      }
    }
  }
  cout << lbest+1 << " " << rbest+1 << " " << ans << endl;
  return 0;
}
