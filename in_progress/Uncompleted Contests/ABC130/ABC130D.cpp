/*  
  Represent contiguous sums as prefix arrays.
  Binary search the left end of the subsequence.
*/
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

const int N = 1e5+5;
ll a[N];
ll pref[N];
ll n, k;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];

  pref[0] = 0;
  for (int i = 0; i < n; i++) pref[i+1] = pref[i] + a[i];

  ll total = 0;
  for (int i = 1; i <= n; i++) {
    if (pref[i] < k) continue;
    ll need = pref[i] - k;
    // need >= pref[idx]
    int lo = 0;
    int hi = i-1;
    int idx = -1;
    while(lo <= hi) {
      int mid = hi-(hi-lo)/2;
      if (need >= pref[mid]){
        idx = mid;
        lo = mid+1;
      }
      else hi = mid-1;
    }
    total += idx+1;
  }
  cout << total << endl;
  return 0;
}
