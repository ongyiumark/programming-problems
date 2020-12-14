#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5;
ll a[N];
ll pref[N];

ordered_set<ll> inversions;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, k; cin >> n >> k;
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }

  pref[0] = a[0];
  for (int i = 1; i < n; i++){
    pref[i] = pref[i-1] + a[i];
  }

  for (int i = 0; i < n; i++){
    pref[i] -= (i+1)*k;
  }

  ll ans = 0;
  for (int i = 0; i < n; i++){
    ans += inversions.size() - inversions.order_of_key(pref[i]);
    inversions.insert(pref[i]);
  }

  for (int i = 0; i < n; i++){
    ans += pref[i] >= 0;
  }

  cout << ans << endl;
  return 0;
}
