#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
  int minX = INF, maxX = -INF, minY = INF, maxY = -INF;
  for (int i = 0; i < n; i++) {
    minX = min(minX, x[i]);
    maxX = max(maxX, x[i]);

    minY = min(minY, y[i]);
    maxY = max(maxY, y[i]);
  }

  int midX = (maxX+minX)/2;
  int midY = (maxY+minY)/2;
  cout << max(maxX-midX, midX-minX) << " " << max(maxY-midY, midY-minY) << "\n";
  return 0;
}