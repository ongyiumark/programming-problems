/*
  WLOG suppose A <= B.
  
  Let C be the largest integer such that C*C < A*B.
  Now, notice that for any i-th place where i <= C in the first contest, 
  we can find a place in the second contest that satisfies the conditions.
  We do this by getting the largest possible k such that i*k < A*B.
  This gives us C pairs.
  If A <= C, then we remove 1.

  Let D be the smallest integer such that D*D > A*B.
  Now, notice that for any i-th place where i >= D in the first contest,
  the largest possible k such that i*k < A*B and has not yet been taken decreases by 1 each time.
  So, that gives us k pairs where D*k < A*B.
  If B <= k, then we remove 1.
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
  
  int q; cin >> q;
  while(q--){
    ll a, b; cin >> a >> b;

    ll lo = 0;
    ll hi = 1e9;
    ll sq = -1;
    while(lo <= hi){
      ll mid = hi-(hi-lo)/2;
      if (mid*mid <= a*b){
        sq = mid;
        lo = mid+1;
      }
      else hi = mid-1;
    }

    ll other = (a*b+sq)/(sq+1)-1;
    ll adjust = 0;
    if (sq*sq == a*b) sq--;
    if (sq >= min(a,b)) adjust--;
    if (other >= max(a,b)) adjust--;
    cout << sq + other + adjust << endl;
  }
  return 0;
}
