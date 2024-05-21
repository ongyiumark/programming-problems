#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0)->sync_with_stdio(false);
  
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n, (1<<30)-1);
    vector M(n, vector(n, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> M[i][j];
        if (i != j) {
          a[i] &= M[i][j];
          a[j] &= M[i][j];
        }
      }
    }

    vector new_M(n, vector(n, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        new_M[i][j] = (i == j ? 0 : a[i]|a[j]);
      }
    }


    if (new_M == M) {
      cout << "YES\n";
      for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i+1==n];
      }
    }
    else {
      cout << "NO\n";
    }
  }
  return 0;
}