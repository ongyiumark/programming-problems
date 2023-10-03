#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int memo[201][11][11][11][11];
bool solve(int i, int s1, int s2, int v1, int v2, vector<int> &s, vector<vector<vector<int>>> &f) {
  if (memo[i][s1][s2][v1][v2] != -1) return memo[i][s1][s2][v1][v2];

  int n = s.size();
  int m = (int)f.size()-1;
  int &res = memo[i][s1][s2][v1][v2];

  if (i == n-1) return res = ((f[v1][v2][s1] == s[i]) && (f[v2][s1][s2] == s[0]));

  res = false;
  for (int v3 = 1; v3 <= m; v3++) {
    if (f[v1][v2][v3] == s[i]) {
      res |= solve(i+1, s1, s2, v2, v3, s, f);
    }
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m; cin >> n >> m;
  vector<vector<vector<int>>> f(m+1, vector<vector<int>>(m+1, vector<int>(m+1)));
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = 1; k <= m; k++) {
        cin >> f[i][j][k];
      }
    }
  }

  vector<int> s(n);
  for (int &x : s) cin >> x;
  
  bool ans = false;
  memset(memo, -1, sizeof memo);
  for (int ci = 1; ci <= m; ci++) {
    for (int cj = 1; cj <= m; cj++) {
      // ci, cj are the first two
      ans |= solve(1, ci, cj, ci, cj, s, f);
    }
  }
  cout << (ans ? "yes\n" : "no\n");
  return 0;
}