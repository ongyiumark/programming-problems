#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, s1, s2; cin >> n >> s1 >> s2;
  vector<int> ar1(s1), ar2(s2), ar(n+1);
  for (int &x : ar1) cin >> x;
  for (int &x : ar2) cin >> x;

  reverse(ar2.begin(), ar2.end());

  unordered_map<int,int> idx;
  vector<int> l(n+1), r(n+1);
  for (int i = 0; i <= n; i++) {
    ar[i] = (i < s1 ? ar1[i] : ar2[i-s1]);
    idx[ar[i]] = i;
    l[i] = i-1;
    r[i] = i+1;
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int ii = idx[i];
    if (l[ii] >= 0 && ar[l[ii]] == 0) ans++;
    if (r[ii] <= n && ar[r[ii]] == 0) ans++;

    if (l[ii] >= 0) r[l[ii]] = r[ii];
    if (r[ii] <= n) l[r[ii]] = l[ii];
  }

  cout << ans << "\n";
  return 0;
}