#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

string next_term(string &s) {
  vector<int> cnt(10);
  for (char &ch : s) cnt[ch-'0']++;

  ostringstream os;
  for (int i = 0; i < 10; i++) {
    if (cnt[i] == 0) continue;
    os << cnt[i] << i;
  }
  return os.str();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s, t; cin >> s >> t;
  unordered_set<string> found;

  int iter = 1;
  int ans = -1;
  if (s == t) ans = iter;
  while (found.find(s) == found.end()) {
    iter++;
    found.insert(s);

    s = next_term(s);
    if (ans == -1 && s == t) ans = iter;
  }

  if (ans == -1) cout << "Does not appear\n";
  else if (iter > 100) cout << "I'm bored.\n";
  else cout << ans << "\n";
  return 0;
}