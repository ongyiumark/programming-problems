#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m; cin >> n >> m;
  vector<string> words(n);
  for (int i = 0; i < n; i++) cin >> words[i];

  int ans = 0;
  for (int j = 0; j < m; j++) {
    vector<int> cnt(26);
    for (int i = 0; i < n; i++) {
      cnt[words[i][j]-'a']++;
    }
    sort(cnt.begin(), cnt.end());
    for (int i = 0; i < 25; i++) {
      ans += cnt[i];
    }
  }
  cout << ans << "\n";
  return 0;
}