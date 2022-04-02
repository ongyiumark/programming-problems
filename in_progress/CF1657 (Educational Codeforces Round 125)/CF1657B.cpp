/*
  Greedily add while you can.
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

void testcase(){
  ll n, b, x, y; 
  cin >> n >> b >> x >> y;

  ll curr = 0;
  ll ans = 0;
  for (int i = 0; i < n; i++){
    if (curr+x <= b) curr += x;
    else curr -= y;
    ans += curr;
  }
  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    testcase();
  }
  
  return 0;
}
