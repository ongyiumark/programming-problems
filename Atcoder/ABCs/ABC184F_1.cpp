/*
  Meet in the middle.
*/

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

  ll n, t; cin >> n >> t;
  vector<ll> ar(n);
  for (int i = 0; i < n; i++) cin >> ar[i];

  if (n == 1) {
    if (ar[0] <= t) cout << ar[0];
    else cout << 0;
    cout << "\n";
    return 0;
  }

  vector<ll> left, right;
  int a = 0, b = (n-1)/2, c = (n-1)/2+1, d = n-1;

  int lsz = b-a+1;
  int rsz = d-c+1;

  // left
  for (int k = 0; k < (1<<lsz); k++) {
    ll total = 0;
    for (int j = 0; j < lsz; j++) {
      if ((1<<j)&k) total += ar[(a+j)];
    }
    left.push_back(total);
  }

  // right
  for (int k = 0; k < (1<<rsz); k++) {
    ll total = 0;
    for (int j = 0; j < rsz; j++) {
      if ((1<<j)&k) total += ar[(c+j)];
    }
    right.push_back(total);
  }
  
  sort(left.begin(), left.end());
  sort(right.begin(), right.end());

  ll ans = 0;
  for (int k = 0; k < (1<<lsz); k++) {
    if (left[k] > t) continue;
    ans = max(ans, left[k] + *prev(upper_bound(right.begin(), right.end(), t-left[k])));
  }
  cout << ans << "\n";
  return 0;
}
