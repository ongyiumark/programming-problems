/*
  Half and halfplus actually tells us the binary representation of the number of apples.
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
  ll n, p; cin >> n >> p;
  ll total = 0;

  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    total |= (s.size() == 8 ? (1LL<<i) : 0);
  }

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += total*p/2;
    total >>= 1;
  }
  cout << ans << endl;
  
  return 0;
}
