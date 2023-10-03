#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ifstream cin("salkan.in");

  int n, k; cin >> n >> k;
  vector<int> a(n), b(n), c(n);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;
  for (int i = 0; i < n; i++) c[i] = a[i]^b[i];

  

  return 0;
}