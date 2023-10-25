#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  bool valid = true;
  for (int i = 0; i < 8; i++) {
    int x; cin >> x;
    if (x == 9) valid = false;
  }
  cout << (valid ? 'S' : 'F') << "\n";

  return 0;
}