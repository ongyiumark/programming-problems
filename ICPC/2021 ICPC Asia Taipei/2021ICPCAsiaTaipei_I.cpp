#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int INF = 1e9;
vector<int> a_max, a_min, b_max, b_min;
void testcase() {
  int s; cin >> s;
  vector<int> a, b;
  int total = 0;
  for (int i = 1; i <= s; i++) {
    int x; cin >> x;
    if (x <= 2) a.push_back(i);
    total -= x*i;
  }
  for (int i = 1; i <= s; i++) {
    int x; cin >> x;
    if (x <= 2) b.push_back(i);
    total += x*i;
  }

  if (total < 0 || total > 2*s*s) {
    cout << -1 << "\n";
    return;
  }
  int n = a.size();
  int m = b.size();
  if ((n == 0 || m == 0) && total != 0) {
    cout << -1 << "\n";
    return;
  }

  a_max.assign(2*s*s+1, -INF), a_min.assign(2*s*s+1, INF);
  a_max[0] = 0;
  a_min[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 2*s*s; j >= 0; j--) {
      a_max[j] = max(a_max[j], j-a[i-1] >= 0 ? a_max[j-a[i-1]]+1 : -INF);
      a_min[j] = min(a_min[j], j-a[i-1] >= 0 ? a_min[j-a[i-1]]+1 : INF);
    }
  }

  b_max.assign(2*s*s+1, -INF), b_min.assign(2*s*s+1, INF);
  b_max[0] = 0;
  b_min[0] = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 2*s*s; j >= 0; j--) {
      b_max[j] = max(b_max[j], j-b[i-1] >= 0 ? b_max[j-b[i-1]]+1 : -INF);
      b_min[j] = min(b_min[j], j-b[i-1] >= 0 ? b_min[j-b[i-1]]+1 : INF);
    }
  }

  for (int k = 0; k <= min(n,m); k++) {
    for (int a_total = 0; a_total <= total; a_total++) {
      if (a_min[a_total] <= k && k <= a_max[a_total] && b_min[total-a_total] <= k && k <= b_max[total-a_total]) {
        cout << k << "\n";
        return;
      }
    }
  }
  cout << -1 << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  while(t--) testcase();

  return 0;
}