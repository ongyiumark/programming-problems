/*
  For each x, get twice the minimum of x and k-x.
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

  int n, k; cin >> n >> k;
  int ans = 0;
  for (int i = 0; i < n; i++){
    int x; cin >> x;
    ans += 2*min(x, k-x);
  }
  cout << ans << endl;
  return 0;
}
