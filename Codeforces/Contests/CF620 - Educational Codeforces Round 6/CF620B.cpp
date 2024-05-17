/*
  Just count.
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
  
  int segs[] = {6,2,5,5,4,5,6,3,7,6};
  int a, b; cin >> a >> b;
  int ans = 0;
  for (int i = a; i <= b; i++) {
    string s = to_string(i);
    for (char ch : s) {
      ans += segs[ch-'0'];
    }
  }
  cout << ans << endl;
  return 0;
}
