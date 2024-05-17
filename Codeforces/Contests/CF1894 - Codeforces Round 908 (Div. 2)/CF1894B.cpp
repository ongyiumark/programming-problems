#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<int> b(n);

    vector<vector<int>> idx(105);
    for (int i = 0; i < n; i++) {
      idx[a[i]].push_back(i);
    }
    int cnt = 0;
    for (int i = 0; i < 105; i++) {
      if (idx[i].size() == 0) continue;
      if (idx[i].size() == 1) {
        b[idx[i][0]] = 1;
        continue;
      }

      bool flag = 0;
      for (int &j : idx[i]) {
        int op = cnt%2;
        if (op == 0) b[j] = flag ? 1 : 2;
        else b[j] = flag ? 2 : 3;
        flag = !flag;
      }
      cnt++;
    }
    if (cnt < 2) cout << -1 << "\n";
    else {
      for (int i = 0; i < n; i++) {
        cout << b[i] << " \n"[i+1==n];
      }
    }
  }
  return 0;
}