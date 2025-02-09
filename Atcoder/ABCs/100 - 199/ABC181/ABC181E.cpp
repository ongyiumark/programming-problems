#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m; cin >> n >> m;
  vector<ll> h(n), w(m);
  for (ll &x : h) cin >> x;
  for (ll &x : w) cin >> x;

  sort(h.begin(), h.end());
  sort(w.begin(), w.end());

  vector<ll> pref_pair(n), suff_pair(n);
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) continue;
    pref_pair[i] = abs(h[i]-h[i-1]);
    if (i-2 >= 0) pref_pair[i] += pref_pair[i-2];
  }

  for (int i = n-1; i >= 0; i--) {
    if (i % 2 == 0) continue;
    suff_pair[i] = abs(h[i]-h[i+1]);
    if (i+2 < n) suff_pair[i] += suff_pair[i+2];
  }

  ll best = 1e18;
  for (ll &x : w) {
    // binary search i such that h[i] <= x
    int lo = 0;
    int hi = n-1;
    int ans = -1;

    while (lo <= hi) {
      int mid = hi - (hi-lo)/2;
      if (h[mid] <= x) {
        ans = mid;
        lo = mid+1;
      }
      else hi = mid-1;
    }

    ll tmp = 0;
    if (ans == -1) {
      tmp = abs(h[0]-x);
      if (n > 1) tmp += suff_pair[1];
    }
    else if (ans == n-1) {
      tmp = abs(h[n-1]-x);
      if (n > 1) tmp += pref_pair[n-2];
    }
    else if (ans % 2 == 0) {
      tmp = abs(h[ans]-x);
      if (ans-1 >= 0) tmp += pref_pair[ans-1];
      if (ans+1 < n) tmp += suff_pair[ans+1];
    }
    else {
      tmp = abs(h[ans+1]-x);
      if (ans >= 0) tmp += pref_pair[ans];
      if (ans+2 < n) tmp += suff_pair[ans+2];
    }
    best = min(best, tmp);
  }

  cout << best << "\n";
  
  return 0;
}
