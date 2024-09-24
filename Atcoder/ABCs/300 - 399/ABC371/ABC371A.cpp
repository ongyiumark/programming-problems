#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(false);
  char ab, ac, bc;
  cin >> ab >> ac >> bc;

  char ca = (ac == '>' ? '<' : '>');
  if (ca == ab) cout << "A";
  else if (ab == bc) cout << "B";
  else cout << "C";

  return 0;
}