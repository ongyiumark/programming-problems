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
  //ld x, y, r; cin >> x >> y >> r;
  ll ans = 0;
  int d; cin >> d;
  for (int i = 0; i*i <= d; i++){
    ans += floor(sqrt(d-i*i));
    
  }
  cout << ans << endl;
  return 0;
}
