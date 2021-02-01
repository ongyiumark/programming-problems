/*
  We fix the middle cut. 
  We now have two segments and we need to split each for them into two.

  Let's consider the left segment L.
  Suppose we split it into 2 segments L1 and L2.
  It's optimal to minimize |L1-L2|. 
  Thus, if we have the prefix sums, the number closest to half of L is where we should cut.
  This can be done with two pointers or binary search.

  A similar process is done for the right segment.
  So, for each middle cut, we know the optimal left cut and right cut.
  Try all middle cuts.
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

const int N = 2e5;
ll pref[N];
ll B[N], D[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  for (int i = 0; i < n; i++){
    int a; cin >> a;
    pref[i] = a;
    if (i > 0) pref[i] += pref[i-1];
  }

  int b = 0;
  for (int c = 1; c < n-2; c++){
    while(b+1 < c && 2*pref[b+1] < pref[c]){
      b++;
    }

    int tb = b;
    if (b+1 < c && pref[c]-2*pref[b] > 2*pref[b+1]-pref[c]){
      tb++;
    }
    B[c] = pref[tb];
  }
  int d = n-2;
  for (int c = n-3; c >= 1; c--){
    while(d-1 > c && 2*(pref[d-1]-pref[c]) > pref[n-1]-pref[c]){
      d--;
    }
    int td = d;
    if (d-1 > c && 2*pref[d]-pref[c]-pref[n-1] > pref[n-1]+pref[c]-2*pref[d-1]){
      td--;
    }
    D[c] = pref[td];
  }

  ll ans = 1e18;
  for (int i = 1; i < n-2; i++){
    ll lo = min({B[i], pref[i]-B[i], D[i]-pref[i], pref[n-1]-D[i]});
    ll hi = max({B[i], pref[i]-B[i], D[i]-pref[i], pref[n-1]-D[i]});
    ans = min(ans, hi-lo);
  }
  cout << ans << endl;
  return 0;
}
