/*
  Count the number of times each element gets included in the sum.
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

const int N = 2e5+5;
ll a[N], pref[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, k; cin >> n >> k;
  
  for (int i = 0; i < n; i++) cin >> a[i];
  pref[0] = 0;
  for (int i = 0; i < n; i++) {
    pref[i+1] = pref[i] + a[i];
  }

  ll total = 0;
  for (int i = 0; i < n-k+1; i++) {
    total += pref[n-i]-pref[i];
  }
  cout << setprecision(11) << fixed << (ld)total/(ld)(n-k+1) << endl;
  return 0;
}
