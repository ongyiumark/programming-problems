#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define int long long

vector<int> solveZ(string s) {
  int n = s.size();
  vector<int> z(n);
  z[0] = 0;

  for (int i = 1, L = 0, R = 0; i < n; i++) {
    if (i <= R) z[i] = min(R-i+1, z[i-L]);
    while (i+z[i] < n && s[z[i]] == s[i+z[i]]) z[i]++;
    if (i+z[i]-1 > R) L = i, R = i+z[i]-1;
  }
  z[0] = n;
  return z;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<vector<string>> names(n, vector<string>(n));
  int total = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> names[i][j];
      if (i != j) total += names[i][j].size();
    }
  }

  if (total % (2*(n-1)) != 0) {
    cout << "NONE\n";
    return 0;
  }

  int S = total / (2*(n-1));

  if (n > 2) {
    int row_total = 0;
    for (int i = 1; i < n; i++) row_total += names[0][i].size();
    if (row_total-S <= 0 || (row_total-S)%(n-2) != 0) {
      cout << "NONE\n";
      return 0;
    }

    int l1 = (row_total-S)/(n-2);
    vector<string> ans;
    ans.push_back(names[0][1].substr(0, l1));
    for (int i = 1; i < n; i++) {
      if (names[0][i].size() <= l1 || l1 == 0) {
        cout << "NONE\n";
        return 0;
      }
      string tmp = names[0][i].substr(l1);
      ans.push_back(tmp);
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j) continue;
        if (ans[i] + ans[j] != names[i][j]) {
          cout << "NONE\n";
          return 0;
        }
      }
    }

    cout << "UNIQUE\n";
    for (int i = 0; i < n; i++) cout << ans[i] << "\n";
  }
  else {
    string s = names[0][1] + "$" + names[1][0];
    string t = names[1][0] + "$" + names[0][1];
    int l1 = names[0][1].size();
    int l2 = names[1][0].size();

    if (l1 != l2) {
      cout << "NONE\n";
      return 0;
   }
    vector<int> z = solveZ(s);
    vector<int> z_other = solveZ(t);

    vector<pair<string, string>> ans;
    int cnt = 0;
    for (int i = l1+1; i < l1+l2+1; i++) {
      if (0 < z[i] && z[i] < l1) {
        if (z_other[l2+1+z[i]] == l1-z[i]) {
          cnt++;
          string n1 = names[0][1].substr(0,z[i]);
          string n2 = names[0][1].substr(z[i]);
          assert(n2 + n1 == names[1][0]);
          ans.push_back({n1, n2});
        }
        if (cnt > 1) {
          cout << "MANY\n";
          return 0;
        }
      }
    }

    if (ans.size() == 0) cout << "NONE\n";
    else {
      cout << "UNIQUE\n";
      cout << ans[0].first << "\n";
      cout << ans[0].second << "\n";
    }
  }

  return 0;
}