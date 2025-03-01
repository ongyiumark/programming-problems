/*
  Keep track of when the water is supposed to stop next and subtract the overlap.
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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, t; cin >> n >> t;
  ll total = 0;
  ll next = 0;
  for (int i = 0; i < n; i++){
    ll x; cin >> x;
    total -= max(next-x,0LL);
    total += t;
    next = x+t;
  }

  cout << total << endl;
  return 0;
}
