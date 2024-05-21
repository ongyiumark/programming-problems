/*
  Not gonna lie, I figured this out by bruteforcing and looking for a pattern.
  Pattern: |x-y| <= 1 is losing.

  This can be proven by induction on x+y because any move will decrease x+y.
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

  ll x, y; cin >> x >> y;
  cout << (abs(x-y) <= 1 ? "Brown" : "Alice") << endl;
  return 0;
}
