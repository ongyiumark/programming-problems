#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

struct FenwickTree {
  vector<int> ft;
  FenwickTree(int n) : ft(n+1) {}
  FenwickTree(const vector<int> &ar) {
    int n = ar.size();
    ft.assign(n+1, 0);
    for (int i = 0; i < n; i++) update(i+1, ar[i]);
  }
  int query(int i) {
    int total = 0;
    while (i > 0) {
      total += ft[i];
      i -= i&(-i);
    }
    return total;
  }
  int query(int l, int r) {
    return query(r)-query(l-1);
  }
  void update(int i, int v) {
    while (i < ft.size()) {
      ft[i] += v;
      i += i&(-i);
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q; cin >> n >> q;
  vector<int> ar(2*n, 1);
  FenwickTree ft(ar);
  while(q--) {
    char ch; cin >> ch;
    if (ch == '-') {
      int i; cin >> i;
      ft.update(i, -1);
      ft.update(i+n, -1);
    }
    else if (ch == '+') {
      int i; cin >> i;
      ft.update(i, 1);
      ft.update(i+n, 1);
    }
    else {
      int a, b; cin >> a >> b;
      if (a > b) swap(a, b);
      if (ft.query(a, b) == b-a+1 || ft.query(b, a+n) == a+n-b+1) cout << "possible\n";
      else cout << "impossible\n";
    }
  }

  return 0;
}