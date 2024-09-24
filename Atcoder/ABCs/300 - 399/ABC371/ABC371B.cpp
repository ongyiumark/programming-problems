#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<bool> has_son(n);

  for (int t = 0; t < m; t++) {
    int i; cin >> i;
    i--;
    char sex; cin >> sex;

    if (sex == 'M') {
      if (!has_son[i]) cout << "Yes\n";
      else cout << "No\n";
      has_son[i] = true;
      continue;
    }

    cout << "No\n";
  }

  return 0;
}