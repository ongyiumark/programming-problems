/*
  Notice that for each column, the dominos can only by one 2x1 or two 1x2's.
  A transition from a 2x1 to another 2x1 will multiply the answer by 2.
  A transition from a 2x1 to a 1x2 will multiply the answer by 2.
  A transition from a 1x2 to a 2x1 does not change the answer.
  A transition from a 1x2 to another 1x2 will multiply the answer by 3.
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

const ll MOD = 1e9+7;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  string s1, s2; cin >> s1 >> s2;
  
  ll ans = (s1[0] == s2[0] ? 3 : 6);
  for (int i = (s1[0] == s2[0] ? 1 : 2); i < n; i++){
    if (s1[i-1] == s2[i-1]) ans = ans*2%MOD;
    else if (s1[i] != s2[i]) ans = ans*3%MOD;

    if (s1[i] != s2[i]) i++; 
  }
  cout << ans << endl;
  return 0;
}
