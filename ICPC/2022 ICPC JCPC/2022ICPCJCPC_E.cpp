#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ld PI = acosl(-1);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ifstream f("bedone.in", ios::in);

  int t; f >> t;
  while(t--) {
    int n; f >> n;
    vector<pair<ll,ll>> p(n);
    for (auto &[x, y] : p) f >> x >> y;

    for (int i = 0; i < n; i++) {
      vector<tuple<ld,int,int>> angles;
      for (int j = 0; j < n; j++) {
        if (i == j) continue;
        ld rad = atan2(p[j].second-p[i].second, p[j].first-p[i].first);
        angles.push_back({rad, p[j].first, p[j].second});
        angles.push_back({rad+2*PI, p[j].first, p[j].second});
      }
      sort(angles.begin(), angles.end());

      int ans = INF;
      for (int i = 0; i < n-1; i++) {
        int j = -1;
        int lo = i;
        int hi = 2*n-3;
        while(lo <= hi) {
          int mid = hi-(hi-lo)/2;
          if (get<0>(angles[mid]) <= get<0>(angles[i])+PI) {
            j = mid;
            lo = mid+1;
          }
          else hi = mid-1;
        }

        int sz = j-i+1;
        ans = min({sz, ans, n-1-sz});
      }
      cout << ans << "\n";
    }
  }

  f.close();

  return 0;
}