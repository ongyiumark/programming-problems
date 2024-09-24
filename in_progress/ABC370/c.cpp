#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(false);
  string s, t; cin >> s >> t;

  vector<string> ans;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] > t[i]) {
      s[i] = t[i];
      ans.emplace_back(s);
    }
  }
  for (int i = n-1; i >= 0; i--) {
    if (s[i] < t[i]) {
      s[i] = t[i];
      ans.emplace_back(s);
    }
  }
  
  int sz = ans.size();
  cout << sz << "\n";
  for (int i = 0; i < sz; i++) {
    cout << ans[i] << "\n";
  }
  return 0;
}