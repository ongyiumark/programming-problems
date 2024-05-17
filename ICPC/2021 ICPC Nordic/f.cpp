#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const ld EPS = 1e-7;
bool gauss_jordan(vector<vector<ld>> &mat) {
  int n = mat.size();
  int m = mat[0].size();
  bool singular = false; // ld det = 1;

  for (int i = 0, p = 0; i < n && p < m; i++, p++) {
    for (int k = i+1; k < n; k++) {
      if (fabsl(mat[k][p]) > EPS) {
        swap(mat[k], mat[i]); // det *= -1;
        break;
      }
    }
    // det *= mat[i][p];
    if (fabsl(mat[i][p]) < EPS) {
      singular = true; i--; continue;
    }
    for (int j = m-1; j >= p; j--) mat[i][j] /= mat[i][p];
    for (int k = 0; k < n; k++) {
      if (i == k) continue;
      for (int j = m-1; j >= p; j--) mat[k][j] -= mat[k][p]*mat[i][j];
    }
  }
  return !singular;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, k; cin >> n >> k;
  ld p; cin >> p;

  int sz = (1<<n);
  vector<vector<ld>> mat(sz, vector<ld>(sz+1, 0));
  for (int mask = 0; mask < sz; mask++) {
    mat[mask][mask] += 1;
    if (__builtin_popcount(mask) >= k) continue;
    mat[mask][1<<n] = 1; // b column
    mat[mask][2*mask%sz] += -(1-p);
    mat[mask][(2*mask+1)%sz] += -p;
  }

  gauss_jordan(mat);
  cout << setprecision(20) << fixed;
  cout << mat[0][sz] << "\n";
  return 0;
}