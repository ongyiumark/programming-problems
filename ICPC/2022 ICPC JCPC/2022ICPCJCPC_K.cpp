#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ifstream cin("hobz.in");

  int t; cin >> t;
  while(t--) {
    string s; cin >> s;
    bool has_zero = false;
    for (char &ch : s) has_zero |= (ch == '0');

    if (has_zero || s.size() >= 2) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}