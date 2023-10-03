#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  string s; cin >> s;

  int ans = 0;
  int j = 0;
  for (int i = 0; i < n; i = j) {
    j = i;
    while ((i+1 < n) && (j < n) && (s[i] == 'a') && (s[i+1] == 'a') && (s[j] == 'a')) j++;
    ans += j-i;
    if (i == j) j++;
  }
  cout << ans << "\n";

  return 0;
}