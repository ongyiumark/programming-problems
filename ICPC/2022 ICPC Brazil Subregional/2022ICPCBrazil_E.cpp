#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6+5;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<int> h(n);
  for (int &x : h) cin >> x;

  vector<int> a(N);
  int ans = 0;
  for (int &x : h) {
    if (a[x] == 0) {
      ans++;
      a[x]++;
    }
    a[x]--;
    a[x-1]++;
  }
  cout << ans << "\n";
  return 0;
}