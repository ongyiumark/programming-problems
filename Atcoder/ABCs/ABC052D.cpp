#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5+1;
ll X[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, a, b; cin >> n >> a >> b;
  for (int i = 0; i < n; i++) cin >> X[i];
  ll ans = 0;
  for (int i = 1; i < n; i++){
    ans += min(a*(X[i]-X[i-1]), b);
  }
  cout << ans << endl;
  return 0;
}
