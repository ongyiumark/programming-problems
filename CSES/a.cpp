#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(false);
  
  int n, m; cin >> n >> m;
  multiset<int> a;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    a.insert(x);
  }

  for (int i = 0; i < m; i++) {
    int longest = *(--a.end());
    int p1 = longest/2;
    int p2 = longest-p1;

    if (p1 > 0 && p2 > 0) {
      a.erase(--a.end());
      a.insert(p1);
      a.insert(p2);
    }

    cout << *(--a.end())-*a.begin() << "\n "[i+1<m];
  }
  return 0;
}