#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ifstream cin("sieve.in");
  int t; cin >> t;
  while(t--) {
    string a, b; cin >> a >> b;
    int n = a.size(); int m = b.size();
    cout << gcd(n, m) << "\n";
  }

  return 0;
}