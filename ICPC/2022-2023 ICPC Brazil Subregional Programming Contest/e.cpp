#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<int> h(n);
  for (int &x : h) cin >> x;

  vector<int> l(n), r(n);
  for (int i = 0; i < n; i++) l[i] = i-1, r[i] = i+1;
  
  vector<bool> popped(n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (popped[i]) continue;
    
    int x = h[i];
    int j = i;
    while (j < n) {
      if (x == h[j]) {
        x--;
        popped[j] = true;
        if (l[j] >= 0) r[l[j]] = r[j];
        if (r[j] < n) l[r[j]] = l[j];
      }
      j = r[j];
    }

    ans++;
  }

  cout << ans << "\n";

  return 0;
}