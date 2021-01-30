/*
  Consider a progression of length k.
  We solve for x: 
    kx + k(k-1)/2 = n.
  
  x is the first element in the sequence, and needs to be an integer.
  Thus, (n-k(k-1)/2)%k = 0.
  Alternatively, [kx + k(k-1)/2]%k = n%k.
  This implies [k(k-1)/2]%k = n%k.

  Now when k is odd, [k(k-1)/2]%k = 0. So, k must divide n.
  Now when k is even, [k(k-1)/2]%k = (k/2)*(-1) = -k/2 = k/2.
    This implies rk + k/2 = n for some r.
    Now, for k to be an integer, (2r+1) must divide n. That is, any odd integer that divides n.
  
  So, for every odd integer that divides n, we can find 2 different progressions.
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
  
  ll n; cin >> n;
  ll ans = 0;
  for (ll i = 1; i*i <= n; i++){
    if (n%i == 0){
      if (i&1) ans+=2;
      if ((n/i)&1) ans+=2;
      if (i*i == n && i&1) ans-=2;
    }
  }
  cout << ans << endl;
  return 0;
}
