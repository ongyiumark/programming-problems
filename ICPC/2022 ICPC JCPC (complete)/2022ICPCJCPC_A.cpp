#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ifstream cin("Round1.in");
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    cout << (n > 26 ? "No\n" : "Yes\n");
  }

  return 0;
}