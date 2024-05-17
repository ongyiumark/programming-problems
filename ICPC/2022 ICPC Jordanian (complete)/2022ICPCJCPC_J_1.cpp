#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll LGN = 31;

ll check(ll k, ll salkan, vector<ll>& basis, int lower_bit) {
  bool valid = true;
  bool is_lower = false;

  for (ll j = LGN; j >= 0; j--) {
    ll salkan_bit = (salkan>>j)&1;
    ll limit_bit = (k>>j)&1;

    if (j >= lower_bit) {
      // exactly same
      if (salkan_bit == limit_bit) continue;
      if (salkan_bit != limit_bit) {
        if (basis[j] == 0) return -1;
        salkan ^= basis[j];
      }
      continue;
    }

    if (salkan_bit == 1 || basis[j] == 0) continue;
    salkan ^= basis[j];
  }
    
  return salkan;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ifstream cin("salkan.in");

  int t; cin >> t;
  while (t--) {
    ll n, k; cin >> n >> k;
    vector<ll> a(n), b(n), c(n), basis(LGN+1);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    for (int i = 0; i < n; i++) c[i] = a[i]^b[i];


    ll salkan = 0;
    for (int i = 0; i < n; i++) salkan ^= a[i];

    int idx = 0;
    vector<int> bit_to_row(LGN+1, -1);
    auto gauss_jordan = [&](vector<ll> &mat) {
      int n = mat.size();
      int m = LGN+1;

      for (int i = 0, p = m-1; i < n && p >= 0; i++, p--) {
        for (int k = i+1; k < n; k++) {
          if ((mat[k]>>p)&1) {
            swap(mat[k], mat[i]); // det *= -1;
            break;
          }
        }
        // det *= mat[i][p];
        if (((mat[i]>>p)&1) == 0) {
          i--; continue;
        }
        bit_to_row[p] = i;
        for (int k = 0; k < n; k++) {
          if (i == k) continue;
          if ((mat[k]>>p)&1) mat[k] ^= mat[i];
        }
      }
    };
    gauss_jordan(c);

    
    for (int j = 0; j <= LGN; j++) {
      if (bit_to_row[j] != -1) basis[j] = c[bit_to_row[j]];
    }

    ll ans = check(k, salkan, basis, -1);
    for (ll j = 0; j <= LGN; j++) {
      ll tmp_k = k;
      if ((k>>j)&1) {
        tmp_k ^= (1LL<<j); 
        ll res = check(tmp_k, salkan, basis, j);  
        ans = max(ans, res);
      }
    }
    cout << (ans == -1 ? 0 : ans) << "\n";
  }

  return 0;
}