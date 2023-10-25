#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  string s; cin >> s;
  int cnt = 0;

  for (int i = 0; i < n; i++) {
    if (s[i] == '1') cnt++;
    else if (i > 1 && (s[i-1] == '1' || s[i-2] == '1')) cnt++;
    else if (i == 1 && s[i-1] == '1') cnt++;
  }
  cout << cnt << "\n";
  return 0;
}