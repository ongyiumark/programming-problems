#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


// point update, range query
struct FenwickTree {
  vector<int> ft;
  FenwickTree(int n) : ft(n+1) {}
  FenwickTree(const vector<int> &ar) {
    int n = ar.size(); ft.assign(n+1, 0);
    for (int i = 1; i <= n; i++) {
      ft[i] += ar[i-1];
      if (i+(i&-i) <= n) ft[i+(i&-i)] += ft[i];
    }
  }
  int query(int i) {
    int total = 0;
    for (; i > 0; i -= (i&-i)) total += ft[i];
    return total;
  }
  int query(int l, int r) { return query(r)-query(l-1); }
  void update(int i, int v) {
    for (; i < ft.size(); i += (i&-i)) 
      ft[i] += v;
  }
};

// range update, point query
struct FenwickRUPQ {
  FenwickTree ft;
  FenwickRUPQ(int m) : ft(m) {}
  void update(int l, int r, int v) {
    ft.update(l, v); ft.update(r+1, -v);
  }
  int query(int i) { return ft.query(i); }
};

// range update, range query
struct FenwickRURQ {
  vector<FenwickRUPQ> ft; 
  int n;

  FenwickRURQ(int n) : ft(2, FenwickRUPQ(n)), n(n) {}
  void update(int l, int r, int v) {
    ft[0].update(l, r, v); // i+(1-1)
    ft[1].update(l, r, v*(1-l));
    if (r+1 <= n) ft[1].update(r+1, n, v*(r-l+1));
  }
  int query(int i) { 
    return ft[0].query(i)*i + ft[1].query(i); 
  }
  int query(int l, int r) { return query(r) - query(l-1); }
};

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    vector<int> pos(n+1);
    for (int i = 1; i <= n; i++) pos[i] = n-i+1;
    int last_pos = n;

    vector<int> a(m);
    for (int &x : a) cin >> x;
    FenwickRURQ ft(n+m);
    ft.update(1, n, 1);
    for (int i = 0; i < m; i++) {
      cout << ft.query(pos[a[i]], last_pos)-1;
      ft.update(pos[a[i]],pos[a[i]],-1);
      pos[a[i]] = ++last_pos;
      ft.update(pos[a[i]],pos[a[i]],1);

      cout << " \n"[i+1==m];
    }
  }
}