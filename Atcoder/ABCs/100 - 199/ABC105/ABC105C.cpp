/*
  Same process with normal bases but floor division doesn't work, so we manually subtract.
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

string solve(ll n){
  if (n == 0) return "0";
  string ans;
  int cnt = 0;
  while(abs(n) > 0){
    ans += (n%2 ? "1" : "0");
    n -= (n > 0 ? n%2 : -(n%2));
    n /= -2;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll n; cin >> n;
  cout << solve(n) << endl;
  return 0;
}
