#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, x, y; cin >> n >> x >> y;

  int cnt = 1;
  while (x%2 == 0 || y%2 == 0) {
    cnt++;
    x /= 2;
    y /= 2;
  }

  cout << n-cnt << "\n";

  return 0;
}