#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int n; cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++)
      cin >> a[i][j];

  int elem = 1;
  for (int i = 0; i < n; i++) {
    if (elem >= i+1) elem = a[elem-1][i];
    else elem = a[i][elem-1];
  }
  cout << elem << "\n";
  return 0;
}