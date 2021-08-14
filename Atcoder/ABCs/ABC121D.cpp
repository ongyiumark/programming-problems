/*
  Use the fact that every four consecutive numbers have an XOR of 0.
    i.e., 0^1^2^3 = 0, 4^5^6^7 = 0, 8^9^10^11 = 0, and so on.
  So, we can ignore the groups of 4 between A and B.
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
  ll a, b; cin >> a >> b;
  ll na = (a+3)/4*4;
  ll nb = b/4*4;
  ll ans = 0;
  for (ll i = a; i < na; i++) {
    ans ^= i;
  }
  for (ll i = nb; i <= b; i++) ans ^= i;
  cout << ans << endl;
  return 0;
}
