/*
  We try all combinations of a+b = n.
  We write a in base 6 and write b in base 9. Sum the digits.
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

int count_base(int x, int b){
  int ans = 0;
  while(x > 0){
    ans += x%b;
    x/=b;
  }
  return ans;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  int ans = 1e9;
  for (int i = 0; i <= n; i++){
    ans = min(ans,count_base(i, 6)+count_base(n-i, 9));
  }
  cout << ans << endl;
  return 0;
}
