/*
  We can modify the goal to have either all 1s or all 0s. 
  This is because if we have all 1s, we can transform it to all 0s with a segment of size |s|.

  Notice that if the i-th and the i+1-th characters of the string are different,
  we need to perform some operation that flips one but not the other.
  To do this, we can either flip [0,i] or [i+1,n).
  So, we do the larger segment of the two.

  Get the minimum of all these (i, i+1) differences.
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
  
  string s; cin >> s;
  int n = s.size();
  int ans = n;

  for (int i = 0; i < n-1; i++){
    if (s[i] != s[i+1]){
      ans = min(ans, max(n-i-1, i+1));
    }
  }
  cout << ans << endl;
  return 0;
}
