#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int n; cin >> n;
  vector<ll> A(n);
  for (ll &x : A) cin >> x;

  vector<ll> ans(n);  
  ll S = 0;
  for (int i = 0; i < n; i++) S += A[i];
  S /= 2;

  ans[0] = S;
  for (int i = 1; i < n-1; i+=2) ans[0] -= A[i];
  for (int i = 1; i < n; i++) ans[i] = A[i-1]-ans[i-1];
  for (int i = 0; i < n; i++) ans[i] *= 2;

  for (int i = 0; i < n; i++) {
    cout << ans[i] << (i+1 < n ? " " : "\n");
  }
  return 0;
}