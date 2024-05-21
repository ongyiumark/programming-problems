#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int dist2(vi &a, vi &b) {
  int n = a.size();
  int res = 0;
  for (int i = 0; i < n; i++) {
    res += (a[i]-b[i])*(a[i]-b[i]);
  }
  return res;
}

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int n, d; cin >> n >> d;
  vector<vi> points(n, vi(d));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < d; j++) {
      cin >> points[i][j];
    }
  }

  int N = 2e4;
  vector<bool> is_square(N);
  for (int i = 0; i*i < N; i++) is_square[i*i] = true;

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      int d2 = dist2(points[i], points[j]);
      ans += is_square[d2];
    } 
  }
  cout << ans << "\n";
  return 0;
}