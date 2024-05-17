#include <bits/stdc++.h>
using namespace std;

void testcase() {
  int n, m; cin >> n >> m;
  vector<int> a(n), b(m);
  for (int &x : a) cin >> x;
  for (int &x : b) cin >> x;

  sort(b.rbegin(), b.rend());
  int i = 0, j = 0;
  vector<int> c;
  while (i < n || j < m) {
    if (i >= n) c.push_back(b[j++]);
    else if (j >= m) c.push_back(a[i++]);
    else {
      if (a[i] > b[j]) c.push_back(a[i++]);
      else c.push_back(b[j++]);
    }
  }

  for (int i = 0; i < n+m; i++) {
    cout << c[i] << " \n"[i+1==n+m]; 
  }
} 

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int t; cin >> t;
  while (t--) testcase();
  return 0;
}