/*
  Split the sequence into 2 and get the n largest from the left and the n smallest from the right.
  Try all splits from n to 2n.
  You can use ordered multisets to keep track of the n largest and smallest.
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

template <typename T>
using ordered_multisetl = __gnu_pbds::tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
using ordered_multisetg = __gnu_pbds::tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 3e5+5;
ll a[N];
ordered_multisetg<ll> l;
ordered_multisetl<ll> r;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  ll total = 0;
  for (int i = 0; i < 3*n; i++) {
    cin >> a[i];
    total += a[i];
  }

  for (int i = 0; i < n; i++) l.insert(a[i]);
  for (int i = n; i < 3*n; i++) r.insert(a[i]);
  ll ans = 1e18;
  ll lsum = 0;
  ll rsum = 0;

  for (int i = 0; i < n; i++) lsum += *l.find_by_order(i), rsum += *r.find_by_order(i);
  ans = lsum-rsum;
  for (int i = n; i < 2*n; i++) {
    int ridx = r.order_of_key(a[i]);
    r.erase(r.find_by_order(ridx));
    l.insert(a[i]);
    int lidx = l.order_of_key(a[i]);
    if (ridx < n) {
      rsum -= a[i];
      rsum += *r.find_by_order(n-1);
    }   
    if (lidx < n) {
      lsum -= *l.find_by_order(n);
      lsum += a[i];
    }
    ans = max(lsum-rsum, ans);
  }

  cout << ans << endl;
  return 0;
}
