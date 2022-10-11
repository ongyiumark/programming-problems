#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll solve(ll x) {
  if (x == 0) return 0;
  
  ll lo = 1;
  ll hi = 1e9;
  ll d = -1;
  while(lo <= hi) {
    ll mid = hi - (hi - lo)/2;
    if (mid*mid <= x) {
      lo = mid+1;
      d = mid;
    }
    else hi = mid-1;
  }

  return (d-1)*3 + (d*d <= x) + (d*d + d <= x) + (d*d + 2*d <= x); 
}

void testcase() {
  ll l, r; cin >> l >> r;
  cout << solve(r) - solve(l-1) << "\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while(t--) testcase();
  return 0;
}
