/*
  Recursively solve the answer.
  For each level, we can compute the number of patties and layers in the burger.
    2^{n+1} - 1 and 2^{n+2}-3.
  Precomputing the values up to n=50 also works.

  B L...L P L...L B
  If x is somewhere in the L's, solve for the lower level by adjusting x.
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

ll fastpow(ll b, ll e){
  ll ans = 1;
  while(e > 0){
    if(e&1) ans *= b;
    e >>= 1;
    b *= b;
  }
  return ans;
}

ll level(ll n){
  return fastpow(2,n+2)-3;
}

ll patties(ll n){
  return fastpow(2,n+1)-1;
}

ll solve(ll n, ll x){
  if (n == 0) return 1;
  if (x == 1) return 0;
  ll prev_level = level(n-1);
  if (x < prev_level+1) return solve(n-1, x-1);
  if (x == prev_level+1) return patties(n-1);
  if (x == prev_level+2) return 1+patties(n-1);
  if (x < 2*prev_level+3) return 1+patties(n-1)+solve(n-1, x-2-prev_level);
  return patties(n);
}

ll n, x;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> x;
  cout << solve(n, x) << endl;
  return 0;
}
