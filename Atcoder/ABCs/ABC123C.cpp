/*
  We simulate the first 5 minutes and all we really care about is how many people are moving from
    city 5 to city 6.
  
  This rate should be constant all throughout until everyone is in city 6, so we just get ceil(n/rate).
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

ll city[5];
ll num[6];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;
  for (int i = 0; i < 5; i++) cin >> city[i];
  
  ll time = 5;
  num[0] = n;
  for (int t = 0; t < 5; t++) {
    for (int i = 4; i >= 0; i--){
      ll moved = min(num[i], city[i]);
      num[i] -= moved;
      num[i+1] += moved;
    }
  }
  time += (n-1)/num[5];
  cout << time << endl;
  return 0;
}
