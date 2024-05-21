/*
  The constraints are small so you can loop through all the integers.
  If the contraints were larger, we can get the gcd and look through the divisors of the gcd.
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
  int a, b, k; cin >> a >> b >> k;
  int i = 0;
  for (i = min(a,b); i >= 1 && k > 0; i--){
    if (a%i == 0 && b%i == 0) k--;
  }
  cout << i + 1 << endl;
  return 0;
}
