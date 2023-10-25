#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string t; cin >> t;
  int n = t.size();
  string p = "ATGC";
  vector<vector<int>> pref(n+1, vector<int>(4, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 4; j++) {
      pref[i][j] = pref[i-1][j] + (p[j]==t[i-1]);
    }
  } 

  int m; cin >> m;
  for (int i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    vector<pair<int,int>> res;
    for (int i = 0; i < 4; i++) {
      res.push_back({-(pref[b][i] - pref[a-1][i]), i});
    }
    sort(res.begin(), res.end());

    for (const auto &[i, j] : res) cout << p[j];
    cout << "\n";
  }

  return 0;
}