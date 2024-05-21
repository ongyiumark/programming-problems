/*
  The order of the foods doesn't matter until the last one.
  The time it takes to order the ith food is the serving time, rounded up to the nearest multiple of 10.
  For the last food, there is no rounding. So, we order the food with the largest round up as last.
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
  int ans = 0;
  int minus = 0;
  for (int i = 0; i < 5; i++) {
    int x; cin >> x;
    ans += (x+9)/10*10;
    minus = max(minus, (x+9)/10*10 - x);
  }
  cout << ans-minus << endl;
  return 0;
}
