#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  int john = 0, mary = 0;
  vector<int> vals(14);
  for (int i = 0; i < 2; i++) {
    int x; cin >> x;
    vals[x]++;
    if (x >= 10) x = 10;
    john += x;
  }
  for (int i = 0; i < 2; i++) {
    int x; cin >> x;
    vals[x]++;
    if (x >= 10) x = 10;
    mary += x;
  }
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    vals[x]++;
    if (x >= 10) x = 10;
    john += x;
    mary += x;
  }


  if (mary >= john) {
    if (vals[23-mary] < 4) cout << 23-mary << "\n";
    else cout << -1 << "\n";
  }
  else {
    for (int i = 24-john; i < 24-mary && i <= 10; i++) {
      if (vals[i] < 4) {
        cout << i << "\n";
        return 0; 
      }
    }
    cout << -1 << "\n";
  }

  return 0;
}