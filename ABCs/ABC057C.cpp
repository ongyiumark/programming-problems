/*
  Get all divisors in O(sqrt(n)).
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

int digits(ll x){
  return floor(log10(x))+1;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin >> n;
  int ans = 1e9;
  for (ll i = 1; i*i <= n; i++){
    if (n%i == 0){
      ans = min(ans, max(digits(i), digits(n/i)));
    }
  }
  cout << ans << endl;
  return 0;
}
