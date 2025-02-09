/* 
  Recursive solution
*/
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

ll solve(ll h) {
  if (h == 1) return 1;
  return 1+2*solve(h/2);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll h; cin >> h;
  cout << solve(h) << "\n";
  return 0;
}
