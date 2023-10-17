#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

const int INF = 1e9;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ifstream cin("milk.in");

  int t; cin >> t;
  while(t--) {
    int n, q; cin >> n >> q;
    n += 1;
    vector<int> a(n);
    a[0] = 0;
    for (int i = 1; i < n; i++) cin >> a[i];

    vector<int> suffmax(n+1, -INF);
    for (int i = n-1; i >= 0; i--) suffmax[i] = max(suffmax[i+1], a[i]);
    vector<ii> increasing;
    for (int i = 0; i < n; i++) increasing.emplace_back(a[i], suffmax[i]);
    sort(increasing.begin(), increasing.end(), [](const ii &left, const ii &right) {
      if (left.first == right.first) return left.second > right.second;
      return left.first < right.first;
    });

    vector<ii> increasing_final;
    increasing_final.push_back(increasing[0]);
    for (int i = 1; i < n; i++) {
      auto &[a, b] = increasing_final.back();
      auto &[c, d] = increasing[i];
      if (a <= c && d <= b) continue;
      increasing_final.push_back({c, d});
    }

    vector<int> suffmin(n+1, INF);
    for (int i = n-1; i >= 0; i--) suffmin[i] = min(suffmin[i+1], a[i]);
    vector<ii> decreasing;
    for (int i = 0; i < n; i++) decreasing.emplace_back(a[i], suffmin[i]);
    sort(decreasing.begin(), decreasing.end(), [](const ii &left, const ii &right) {
      if (left.first == right.first) return left.second < right.second;
      return left.first > right.first;
    });

    vector<ii> decreasing_final;
    decreasing_final.push_back(decreasing[0]);
    for (int i = 1; i < n; i++) {
      auto &[a, b] = decreasing_final.back();
      auto &[c, d] = decreasing[i];
      if (a >= c && d >= b) continue;
      decreasing_final.push_back({c, d});
    }

    while(q--) {
      int u, v; cin >> u >> v;
      if (u <= v) {
        int lo = 0;
        int hi = (int)increasing_final.size() - 1;
        int ans = -1;
        while (lo <= hi) {
          int mid = hi - (hi-lo)/2;
          auto &[ca, cb] =  increasing_final[mid];
          if (ca <= u) {
            ans = mid;
            lo = mid+1;
          }
          else hi = mid-1;
        }
        if (ans == -1) {
          cout << "No\n";
          continue;
        }

        auto &[a, b] =  increasing_final[ans];
        if (a <= u && v <= b) cout << "Yes\n";
        else cout << "No\n";
      }
      else if (u > v) {
        int lo = 0;
        int hi = (int)decreasing_final.size() - 1;
        int ans = -1;
        while (lo <= hi) {
          int mid = hi - (hi-lo)/2;
          auto &[ca, cb] =  decreasing_final[mid];
          if (ca >= u) {
            ans = mid;
            lo = mid+1;
          }
          else hi = mid-1;
        }
        if (ans == -1) {
          cout << "No\n";
          continue;
        }

        auto [a, b] = decreasing_final[ans];
        if (a >= u && v >= b) cout << "Yes\n";
        else cout << "No\n";
      }

    }
  }

  return 0;
}