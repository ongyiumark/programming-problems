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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while(t--) {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    // separate case
    if (k == 4) {
      int cnt_div2 = 0, cnt_div4 = 0;
      for (int i = 0; i < n; i++) {
        cnt_div2 += (a[i] % 2 == 0);
        cnt_div4 += (a[i] % 4 == 0);
      }
      if (cnt_div2 >= 2 || cnt_div4 >= 1) {
        cout << 0 << "\n";
        continue;
      }

      if (n == 1) {
        cout << k - a[0]%k << "\n";
        continue;
      }

      if (cnt_div2 == 1) {
        cout << 1 << "\n";
        continue;
      }

      int ans = 2;
      for (int i = 0; i < n; i++) ans = min(ans, k-a[i]%k);
      cout << ans << "\n";
    }
    else {
      bool is_div = false;
      for (int i = 0; i < n; i++) is_div |= (a[i] % k == 0);
      if (is_div) {
        cout << 0 << "\n";
        continue;
      }

      int ans = k;
      for (int i = 0; i < n; i++) ans = min(ans, k-a[i]%k);
      cout << ans << "\n";
    }
  }
  
  return 0;
}
