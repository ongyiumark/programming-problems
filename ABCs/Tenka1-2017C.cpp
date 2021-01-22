/*
  Since there's a guarantee answer less than 3500, simply try all possibilities.
  Reduce O(n^3) solution to O(n^2) with algebra.
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

  ll n; cin >> n;
  for (ll a = 1; a <= 3500; a++){
    for (ll b = 1; b <= 3500; b++){
      ll r = n*a*b;
      ll l = 4*a*b-n*b-n*a;
      if (l <= 0) continue;
      if (r%l) continue;
      ll c = r/l;
      if (c >= 1 && c <= 3500){
        cout << a << " " << b << " " << c << endl;
        return 0;
      }
    }
  }
  return 0;
}
