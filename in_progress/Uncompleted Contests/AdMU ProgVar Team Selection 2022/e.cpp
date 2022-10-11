#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 3e5+5;
ll a[N], b[N];
pair<ll,ll> p[N];
ll pref[N];

ll range(int l, int r) {
  if (l == 0) return pref[r];
  return pref[r]-pref[l-1];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    p[i] = {b[i], a[i]};
  }

  sort(p, p+n);
  for (int i = 0; i < n; i++) {
    pref[i] = p[i].second;
    if (i > 0) pref[i] += pref[i-1];
  }

  for (int i = 0; i < n; i++) {
    cout << p[i].second << " " << p[i].first << endl;
  }


  ll res = 0;
  for (int i = 0; i < n; i++) {
    int lo = 0;
    int hi = n-i-1;
    ll ans = -1;
    while(lo <= hi) {
      int mid = hi - (hi-lo)/2;
      if (range(i, i+mid) <= (i+mid-i+1)*p[i].first) {
        ans = i+mid-i+1;
        lo = mid+1;
      }
      else hi = mid-1;
    }

    res = max(res, ans);
  }

  cout << res << endl;

  
  return 0;
}
