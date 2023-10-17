#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;

struct segtree {
  vi vals, deltas;
  int n;
  segtree(vi &ar) {
    n = ar.size();
    vals.assign(4*n, 0);
    deltas.assign(4*n, 0);
    build(ar, 1, 0, n-1);
  }
  
  void build(vi &ar, int p, int i, int j) {
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

  void update(int l, int r, int v, int p, int i, int j) {
    push(p, i, j);
    if (l <= i && j <= r) {
      deltas[p] += v;
      push(p, i, j);
    }
    else if (j < l || r < i) {}
    else {
      int k = (i+j)/2;
      update(l, r, v, p<<1, i, k);
      update(l, r, v, p<<1|1, k+1, j);
      pull(p);
    }
  }

  int query(int l, int r, int p, int i, int j) {
    push(p, i, j);
    if (l <= i && j <= r) return vals[p];
    else if (j < l || r < i) return 0;
    else {
      int k = (i+j)/2;
      return query(l, r, p<<1, i, k) + query(l, r, p<<1|1, k+1, j);
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int n, m, k; cin >> n >> m >> k;
  vi months(n);
  for (int &x : months) cin >> x;

  stack<ii> s;
  vi p(n);
  segtree st(p);

  int ans = 0;
  for (int i = 0; i < n; i++) {
    s.push({i, months[i]});
    int current_paid = st.query(i, i, 1, 0, n-1);
    if (current_paid >= k) continue;

    for (int j = 0; j < n; j++) {
      cout << st.query(j, j, 1, 0, n-1) << " ";
    }
    cout << endl;
    while(!s.empty()) {
      auto [month, flights] = s.top();
      s.pop();
      int to_pay = k-current_paid;
      if (to_pay == 0) break;

      int l = month-(m-1);
      int r = month+(m-1);
      l = max(0, l);
      r = min(n-1, r);

      if (flights > to_pay) {
        st.update(l, r, to_pay, 1, 0, n-1);
        current_paid += to_pay;
        flights -= to_pay;
        ans == to_pay;
        s.push({month, flights});

        break;
      }
      else {
        st.update(l, r, flights, 1, 0, n-1);
        current_paid += flights;
        ans += flights;
      }
    }
  }

  cout << ans << "\n";
  return 0;
}