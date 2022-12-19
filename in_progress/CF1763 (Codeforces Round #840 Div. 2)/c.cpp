#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5+5;
const int INF = 1e9;
ll a[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    ll hi = -INF;
    for (int i = 0; i < n; i++) {
      hi = max(hi, a[i]);
    }

    if (n >= 4) {
      cout << hi*n << "\n";
      continue;
    }

    if (n == 2) {
      cout << max(a[0]+a[1], abs(a[0]-a[1])*2) << "\n";
    }
    else {
      if (a[0] == hi || a[2] == hi) {
        cout << hi*3 << "\n";
      }
      else {
        cout << max({a[0]+a[1]+a[2], 2*abs(a[0]-a[1])+a[2], a[0]+2*abs(a[1]-a[2]), 3*abs(a[0]-a[1]), 3*abs(a[1]-a[2]), 3*a[2], 3*a[0]}) << "\n";
      }
    }

  }
  
  return 0;
}
