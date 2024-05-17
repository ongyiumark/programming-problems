#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct segtree {
  vector<ll> st; int n;
  vector<int> pos;
  segtree(vector<int> &ar) {
    n = ar.size();
    st.resize(2*n, 0);
    pos.resize(n, 0);
    for (int i = 0; i < n; i++) {
      st[i+n] = ll(ar[i])*ar[i];
      pos[i] = ar[i];
    }
    for (int p = n-1; p > 0; p--) st[p] = st[p<<1] + st[p<<1|1];
  }

  ll query(int l, int r) {
    ll res = 0;
    for (l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
      if (l&1) res += st[l++];
      if (r&1) res += st[--r];
    }
    return res;
  }

  void update(int p, ll v) {
    for (st[p += n] = v; p >>= 1; )
      st[p] = st[p<<1] + st[p<<1|1];
  }

  void add(int x) {
    int i = lower_bound(pos.begin(), pos.end(), x)-pos.begin();
    //cout << "yeet " << i << " " << n << endl;
    pos[i]++;
    if (i+1 < n && pos[i] >= pos[i+1]) { // swap
      swap(pos[i], pos[i+1]);
      update(i, ll(pos[i])*pos[i]);
      update(i+1, ll(pos[i+1])*pos[i+1]);
    }
    else update(i, ll(pos[i])*pos[i]);
  }

  void minus(int x) {
    int i = lower_bound(pos.begin(), pos.end(), x)-pos.begin();
    pos[i]--;
    if (i > 0 && pos[i] <= pos[i-1]) { // swap
      swap(pos[i], pos[i-1]);
      update(i, ll(pos[i])*pos[i]);
      update(i-1, ll(pos[i-1])*pos[i-1]);
    }
    else update(i, ll(pos[i])*pos[i]);
  }

  ll query_bound(ll l, ll r) {
    int i = lower_bound(pos.begin(), pos.end(), l)-pos.begin();
    int j = upper_bound(pos.begin(), pos.end(), r)-pos.begin();
    j--;
    if (i > j) return 0;
    return query(i, j);
  }
};
int main(){
  cin.tie(0)->sync_with_stdio(false);
  
  int n, q; cin >> n >> q;
  vector<int> a(n+1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  //for (int &x : a) cin >> x;
  vector<vector<int>> ar_vals(n+1, vector<int>());
  vector<segtree*> sts(n+1);
  for (int i = 1; i <= n; i++) ar_vals[a[i]].emplace_back(i);
  for (int i = 1; i <= n; i++) {
    if (ar_vals[i].size() == 0) continue;
    sts[i] = new segtree(ar_vals[i]);
  }

  ll last = 0;
  while (q--) {
    int t; cin >> t;
    if (t == 1) {
      ll p_1; cin >> p_1;
      //cout << "yeet " << p_1 << endl;
      ll p = (p_1 + last - 1)%(n-1)+1;

      //cout << "q1 " << p << endl; 
      sts[a[p]]->add(p);
      sts[a[p+1]]->minus(p+1);
      swap(a[p], a[p+1]);
    }
    else {
      ll l_1, r_1, x_1; cin >> l_1 >> r_1 >> x_1;
      ll l = (l_1 + last - 1)%n+1;
      ll r = (r_1 + last - 1)%n+1;
      ll x = (x_1 + last - 1)%n+1;
      if (l > r) swap(l, r);

      
      if (t == 3) {
        //cout << "q3 " << l << " " << r << " " << x << endl;
        if (ar_vals[x].size() == 0) {
          last = 0;
          cout << last << "\n";
          continue;
        }
        last = sts[x]->query(l-1, r-1);
        cout << last << "\n";
      }
      else {
        //cout << "q2 " << l << " " << r << " " << x << endl;
        if (ar_vals[x].size() == 0) {
          last = 0;
          cout << last << "\n";
          continue;
        }
        last = sts[x]->query_bound(l, r);
        cout << last << "\n";
        // for (int i : sts[x]->pos) {
        //   cout << i << " ";
        // }
        // cout << endl;
      }
    }
    // for (int i = 1; i <= n; i++) {
    //   cout << a[i] << " ";
    // }
    // cout << endl;
  }

  return 0;
}