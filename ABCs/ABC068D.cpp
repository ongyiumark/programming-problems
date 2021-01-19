/*
  You can start at k = 0 and work your way up: {n-1, n-1, ... , 0}.
  Add n to the smallest and subtract 1 from the rest.
  
  Notice that a pattern emerges every n.
  That is, the sequence for k and the sequence for k+n differ by exactly 1 for each element.
  So, you only need to compute for the sequence for k%n. Simply add k/n to each element after.
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll k; cin >> k;
  ll add = k/50;
  ll type = k%50;
  vector<ll> ans(50, 49);
  ans[0] = 0;

  for (int i = 0; i < type; i++){
    sort(ans.begin(), ans.end());
    ans[0] += 50;
    for (int i = 1; i < 50; i++){
      ans[i]--;
    }
  }
  cout << 50 << endl;
  for (int i = 0; i < 50; i++){
    cout << ans[i]+add;
    cout << (i == 49 ? "\n" : " ");
  }
  
  return 0;
}
