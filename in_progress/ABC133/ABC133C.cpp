/*
  Numbers mod 2019 repeat, so we only need to check up to l+2019.
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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll l, r; cin >> l >> r;
  ll best = 2020;
  for (ll i = l; i <= min(l+2020,r); i++) {
    for (ll j = i+1; j <= min(l+2020,r); j++){
      best = min(best, i*j%2019);
    }
  }
  cout << best << endl;
  return 0;
}
