/*
  Binary search for the closest cell towers for each city.
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<int,pair<int,int>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5+5;
const ll INF = 1e18;
ll a[N], b[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];

  ll best = 0;
  for (int i = 0; i < n; i++) {
    int lo = 0;
    int hi = m-1;
    int idx = -1;
    while(lo <= hi) {
      int mid = hi - (hi-lo)/2;
      if (a[i] >= b[mid]) {
        idx = mid;
        lo = mid+1;
      }
      else hi = mid-1;
    }

    ll curr = INF;
    if (0 <= idx && idx < m) curr = min(curr,abs(a[i]-b[idx]));
    if (0 <= idx+1 && idx+1 < m) curr = min(curr,abs(a[i]-b[idx+1]));
    best = max(curr,best);
  }
  cout << best << endl;
  
  return 0;
}
