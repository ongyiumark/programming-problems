#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int n, a, b; cin >> n >> a >> b;
  cout << min(n*a, b) << "\n";
  return 0;
}