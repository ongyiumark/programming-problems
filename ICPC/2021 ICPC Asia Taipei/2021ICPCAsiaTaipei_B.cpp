#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

void testcase() {
  int n; cin >> n;
  string s, t; cin >> s >> t;
  vector<bool> normal(n), reversed(n);
  for (int i = 0; i < n; i++) normal[i] = (s[i] == t[i]);
  for (int i = 0; i < n; i++) reversed[i] = (s[i] == t[n-i-1]);
  vector<int> pref_n(n), pref_r(n);
  for (int i = 0; i < n; i++) {
    pref_n[i] = normal[i];
    pref_r[i] = reversed[i];
    if (i > 0) {
      pref_n[i] += pref_n[i-1];
      pref_r[i] += pref_r[i-1];
    }
  }

  auto count_normal = [&](int l, int r) {
    if (r < l) return 0;
    if (l == 0) return pref_n[r];
    return pref_n[r]-pref_n[l-1];
  };
  vector memo(n, vector(n, -1));
  function<int(int,int)> count_reversed = [&](int l, int r) -> int {
    int &ans = memo[l][r];
    if (ans != -1) return ans;
    if (r < l) return ans = 0;
    if (l == r) return ans = (s[l] == t[l]);
    
    ans = (s[l] == t[r])+(s[r] == t[l])+count_reversed(l+1, r-1);
    return ans;
  };

  int best = 0;
  for (int a = 0; a < n; a++) {
    for (int b = a; b < n; b++) {
      best = max(best, count_normal(0, a-1) + count_reversed(a, b) + count_normal(b+1, n-1));
    }
  }

  int besta, bestb;
  for (int len = 1; len <= n; len++) {
    for (int a = 0; a < n && a+len-1 < n; a++) {
      int b = a+len-1;
      int tmp = count_normal(0, a-1) + count_reversed(a, b) + count_normal(b+1, n-1);
      if (tmp == best) {
        besta = a+1;
        bestb = b+1;
        goto outside;
      }
    }
  }
  outside:


  cout << pref_n[n-1] << " " << best << " " << besta << " " << bestb << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;
  while(t--) testcase();

  return 0;
}