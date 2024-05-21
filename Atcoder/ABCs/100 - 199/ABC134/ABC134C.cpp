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
  cin.tie(0)->sync_with_stdio(false);
  
  int n; cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  
  vector<int> pref(n), suf(n);
  pref[0] = a[0];
  for (int i = 1; i < n; i++) pref[i] = max(pref[i-1], a[i]);

  suf[n-1] = a[n-1];
  for (int i = n-2; i >= 0; i--) suf[i] = max(suf[i+1], a[i]);

  for (int i = 0; i < n; i++) {
    if (i == 0) cout << suf[i+1] << "\n";
    else if (i == n-1) cout << pref[i-1] << "\n";
    else cout << max(pref[i-1], suf[i+1]) << "\n";
  }
  return 0;
}
