#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, k; cin >> n >> k;
  vector<ll> r(1<<n);
  for (int i = 0; i < (1<<n); i++) cin >> r[i];
  sort(r.rbegin(), r.rend());

  ll total = 0;
  for (int i = 0; i < n; i++) {
    

    int lo = (1<<i);
    int hi = (1<<(i+1))-1;

    int j = 0;
    while(j < (1<<i)) {
      int tlo = lo;
      int thi = hi;
      int tans = -1;

      while(tlo <= thi) {
        int mid = thi - (thi-tlo)/2;
        if (r[j]-r[mid] <= k) {
          tans = mid;
          tlo = mid+1;
        }
        else thi = mid-1;
      }

      if (tans == -1) {
        j++;
        hi--;
      }
      else {
        total += (tans-lo+1);
        j += (tans-lo+1);
        lo += (tans-lo+1);
      }
    }
  }
  cout << total << "\n";

  return 0;
}