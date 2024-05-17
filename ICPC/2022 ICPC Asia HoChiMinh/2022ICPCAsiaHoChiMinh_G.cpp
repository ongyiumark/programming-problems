#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;


int main() {
  cin.tie(0)->sync_with_stdio(false);
  int n, r, x1, x2; cin >> n >> r >> x1 >> x2;
  bool in_goal = 0;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    if (x1 < x2 && p[i]+r <= x1) in_goal = 1;
    if (x1 > x2 && p[i]-r >= x1) in_goal = 1;
  }
  cout << (in_goal ? "GOAL" : "NO GOAL") << "\n";
}