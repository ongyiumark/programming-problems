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

const int INF = 1e9;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = a[n-1]-a[0];
    for (int i = 0; i < n-1; i++) ans = max(ans,a[i]-a[i+1]);

    int hi = -INF;
    for (int i = 1; i < n; i++) hi = max(hi, a[i]);
    int lo = INF;
    for (int i = 0; i < n-1; i++) lo = min(lo, a[i]);

    ans = max(ans, hi-a[0]);
    ans = max(ans, a[n-1]-lo);
    cout << ans << endl;
  }
  
  return 0;
}
