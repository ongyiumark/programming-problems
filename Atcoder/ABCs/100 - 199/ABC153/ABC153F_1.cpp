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

const int N = 2e5+5;
int n, d, a;
pair<ll,ll> xh[N];

struct segtree {
  vector<ll> vals;
  vector<ll> deltas;
  int n;

  segtree(vector<ll> &ar) {
    n = ar.size();
    vector<ll>(4*n).swap(vals);
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
    vals[p] = vals[p<<1] + vals[p<<1|1];
  }

  void push(int p, int i, int j) {
    if (deltas[p]) {
      vals[p] += (j-i+1)*deltas[p];
      if (i != j) {
        deltas[p<<1] += deltas[p];
        deltas[p<<1|1] += deltas[p];
      }
      deltas[p] = 0;
    }
  }

  void update(int l, int r, ll v, int p, int i, int j) {
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
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> d >> a;
  for (int i = 0; i < n; i++) {
    cin >> xh[i].first >> xh[i].second; 
  }
  sort(xh, xh+n);

  vector<ll> ar(n);
  for (int i = 0; i < n; i++) {
    ar[i] = xh[i].second;
  }

  segtree st(ar);

  int i = 0;
  int j = 1;
  ll cnt = 0;
  
  while (i < n) {
    while (j < n && xh[i].first + 2*d >= xh[j].first) j++;

    ll tmp = (st.query(i, i, 1, 0, n-1)+a-1)/a;
    cnt += tmp;

    st.update(i, j-1, -tmp*a, 1, 0, n-1);

    while(i < n && st.query(i, i, 1, 0, n-1) <= 0) {
      i++;
    }
  }

  cout << cnt << "\n";
  
  return 0;
}
