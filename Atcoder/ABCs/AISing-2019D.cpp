/*
  My solution involves nested binary searches.
  First, we sort the cards in ascending order.
  Notice that Takahashi will always get some number of the highest cards, 
    followed by alternating the highest card with Aoki.
  If we label the cards with 'A' and 'T', it'll look like this: ...ATATAAAATTTT
  
  We can binary search for the number of highest cards Takahashi will take.
  Once we know this, we can compute for the answer using prefix sums.
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
int n, q;
ll prefix[N];
ll alternate[N];

// Find the position of x when inserted into A.
int find_pos(ll x){
  int ans = -1;
  int lo = 0;
  int hi = n-1;
  while(lo <= hi){
    int mid = hi-(hi-lo)/2;
    if (A[mid] < x) {
      ans = mid;
      lo = mid+1;
    }
    else hi = mid-1;
  }
  return ans+1;
}

ll solve(ll x){
  int pos = find_pos(x);
  
  int lo = pos;
  int hi = n-2;
  int ans = pos-1;
  while(lo <= hi){
    int mid = hi - (hi-lo)/2;
    ll d = A[mid]-x;
    int taken = mid - find_pos(x-d)+1;
    if (taken <= n-mid-1){
      ans = mid;
      lo = mid+1;
    }
    else hi = mid-1;
  }
  ll total = prefix[n-1];
  if (ans >= 0) total -= prefix[ans];
  
  int top = n-ans-1;
  // Aoki will take everything from ans-top+1 to ans

  if (ans-top >= 0) total += alternate[ans-top];
  return total;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> A[i];
  prefix[0] = A[0];
  for (int i = 1; i < n; i++){
    prefix[i] = A[i] + prefix[i-1];
  }
  alternate[0] = A[0];
  alternate[1] = A[1];
  for (int i = 2; i < n; i++){
    alternate[i] = alternate[i-2] + A[i];
  }

  sort(A, A+n);
  for (int i = 0; i < q; i++){
    ll x; cin >> x;
    cout << solve(x) << endl;
  }
  return 0; 
}
