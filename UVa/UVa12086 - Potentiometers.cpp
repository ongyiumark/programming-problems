#include <bits/stdc++.h>
using namespace std;

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


int main() {
  cin.tie(0)->sync_with_stdio(false);

  int case_no = 0;
  while (true) {
    int n; cin >> n;
    case_no++;
    if (n == 0) break;
    if (case_no > 1) cout << "\n";
    cout << "Case " << case_no << ":\n";

    vector<int> ar(n);
    for (int &x : ar) cin >> x;
    FenwickTree ft(ar);
    while (true) {
      string op; cin >> op;
      if (op == "END") break;

      if (op == "S") {
        int x, r; cin >> x >> r;
        ft.update(x, r-ft.query(x,x));
      }
      else {
        int x, y; cin >> x >> y;
        cout << ft.query(x,y) << "\n";
      }
    }
  }
}