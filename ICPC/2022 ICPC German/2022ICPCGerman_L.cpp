#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int l, w, n; cin >> l >> w >> n;
  if (l*w%n != 0) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }


  int area = l*w/n;
  for (int a = 1; a <= area; a++) {
    if (area%a != 0) continue;
    int b = area/a;
    if ((l%a != 0)||(w%b != 0)) continue;
    int id = 0;
    vector grid(l, vector(w, '.'));
    for (int i = 0; i < l; i += a) {
      for (int j = 0; j < w; j += b) {
        for (int ii = 0; ii < a; ii++) {
          for (int jj = 0; jj < b; jj++) {
            grid[i+ii][j+jj] = (id+'A');
          }
        }
        id++;
      }
    }

    for (int i = 0; i < l; i++) {
      for (int j = 0; j < w; j++) cout << grid[i][j];
      cout << "\n";
    }
    return 0;
  }

  cout << "IMPOSSIBLE\n";

  return 0;
}