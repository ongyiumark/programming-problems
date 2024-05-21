/*
  Use prefix sums.
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5;
ll a[N];
ll pref[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  pref[0] = a[0];
  for (int i = 1; i < n; i++){
    pref[i] = pref[i-1] + a[i];
  }


  ll ans = 1e18;
  for (int i = 0; i < n-1; i++){
    ans = min(ans, abs(2*pref[i]-pref[n-1]));
  }
  cout << ans << endl;
  return 0;
}
