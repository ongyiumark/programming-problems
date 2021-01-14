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

  ll n; cin >> n;
  ll ans = 1;
  for (int i = 1; i <= n; i++){
    ans = (ans * i)%MOD;
  }
  cout << ans << endl;
  return 0;
}
