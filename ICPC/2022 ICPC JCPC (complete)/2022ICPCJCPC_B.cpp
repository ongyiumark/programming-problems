#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ifstream cin("hanya.in");

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n);
    int neg = 0, pos = 0;
    for (int &x : a) {
      cin >> x;
      pos += x > 0;
      neg += x < 0;
    }

    if (neg == 0 && pos == 0) cout << 0 << "\n";
    else if (neg == 0 || pos == 0) cout << 1 << "\n";
    else cout << 2 << "\n";

  }

  return 0;
}