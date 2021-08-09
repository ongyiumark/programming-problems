/*
  We build the best candidate by going through each bit.
  If there are more 0's than 1's in A, then we turn on that bit.
  However, we need to keep in mind that it has to be less than K.
    We can only turn on the bit if that bit of K is on or if our candidate is already less.  
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

const int N = 1e5+5;
ll A[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, k; cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> A[i];

  // Go through each bit
  ll best = 0;
  bool less = false;
  for (int b = 40; b >= 0; b--){
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if ((1LL<<b)&A[i]) cnt++;
    }

    // Majority is 0
    if (2*cnt <= n) {
      if (less || (1LL<<b)&k) best |= (1LL<<b);
    }
    else if ((1LL<<b)&k) less = true;
  }  
  
  ll ans = 0;
  for (int i = 0; i < n; i++){
    ans += best^A[i];
  }
  cout << ans << endl;
  return 0;
}
