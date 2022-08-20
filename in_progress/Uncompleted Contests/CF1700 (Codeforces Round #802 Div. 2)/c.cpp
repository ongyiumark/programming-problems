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

const int N = 2e5+5;
vector<int> a(N);

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n == 1) {
      cout << abs(a[0]) << endl;
      continue;
    }
    ll smol = 1e18;
    ll ans = 0;
    ll sub = 0;
    for (int i = 0; i < n-1; i++) {
      ans += abs(a[i]-a[i+1]);
      if (a[i] >= a[i+1]) {
        smol = min((ll)a[i+1]-sub, smol);
      }
      else {
        sub += abs(a[i]-a[i+1]);
        smol = min((ll)a[i+1]-sub, smol);
      }
    }
    ans += abs(smol);
    cout << ans << endl;
  }
  
  return 0;
}
