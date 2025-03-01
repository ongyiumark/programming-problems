/*
  Alternate 5 and 6.
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
  ll x; cin >> x;
  ll cnt = x/11;
  int mod = x%11;

  if (mod == 0) cout << cnt*2;
  else if (mod <= 6) cout << cnt*2 + 1;
  else cout << cnt*2 + 2;
  cout << endl;
  return 0;
}
