#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, c; cin >> n >> c;
  vector<string> words(n);
  vector<int> pos(n);
  for (string &s : words) cin >> s;
  for (int i = 0; i < n; i++) {
    string s = words[i];
    pos[i] = find(s.begin(), s.end(), '*') - s.begin();
  }

  map<string, int> cnt;
  for (int i = 0; i < n; i++) {
    for (char ch = 'a'; ch <= 'z'; ch++) {
      words[i][pos[i]] = ch;
      cnt[words[i]]++;
    }
  }
  vector<pair<int, string>> ans;
  for (auto &[key, val] : cnt) {
    ans.push_back({-val, key});
  } 
  sort(ans.begin(), ans.end());
  auto [val, s] = ans[0]; 
  cout << s << " " << -val << "\n";

  return 0;
}