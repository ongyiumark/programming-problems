#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  while(t--) {
    bool is_dec = false;
    bool is_below = false;

    string s; cin >> s;
    int n = s.size();
    for (int i = 1; i < n; i++) {
      if (s[i-1] > s[i]) is_dec = true;
      if (is_dec && s[i] > s[i-1]) {
        s[i] = s[i-1];
        is_below = true;
      }
      if (is_below && s[i-1] > s[i]) s[i] = s[i-1];
    }
    cout << s << "\n";
  }
  return 0;
}