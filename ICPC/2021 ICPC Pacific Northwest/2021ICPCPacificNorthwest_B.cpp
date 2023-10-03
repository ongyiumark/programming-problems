#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string v; cin >> v;
  string s; cin >> s;
  int n = s.size();

  int shortest = 1;
  int cnt = v.size();
  vector<bool> vis(26);
  for (int i = 0; i < n; i++) {
    if (!vis[s[i]-'a']) {
      vis[s[i]-'a'] = true;
      cnt--;
    }

    if (cnt == 0) {
      cnt = v.size();
      shortest++;
      fill(vis.begin(), vis.end(), false);
    }
  }

  vector<vector<int>> precomp(n, vector<int>(26, n));
  for (int i = n-1; i >= 0; i--) {
    for (int j = 0; j < 26; j++) {
      if(s[i]-'a' == j) precomp[i][j] = i;
      if (i+1 < n) precomp[i][j] = min(precomp[i][j], precomp[i+1][j]);
    }
  }

  int q; cin >> q;
  for (int i = 0; i < q; i++) {
    string t; cin >> t;

    if (t.size() != shortest) cout << 0 << "\n";
    else {
      bool is_subseq = true;
      int j = 0;
      for (char ch : t) {
        if (j >= n) {
          is_subseq = false;
          break;
        }
        j = precomp[j][ch-'a']+1;
      }
      if (j > n) is_subseq = false;
      cout << (is_subseq ? 0 : 1) << "\n";

    }
  }

  return 0;
}