#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;

template <typename T>
using ordered_set = tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<ll> a(2*n), b(2*n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i+n] = a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    b[i+n] = b[i];
  }

  ll k, l; cin >> k >> l;

  ll totalA = 0, totalB = 0;
  ordered_set<ll> os;
  for (int i = 0; i < k; i++) {
    totalA += a[i];

    if (os.size() < l) totalB += b[i];
    else if (os.order_of_key(b[i]+1) < l) {
      totalB -= *os.find_by_order(l-1);
      totalB += b[i];
    } 
    os.insert(b[i]);
  }
  assert(os.size() == k);

  ll ans = totalA + totalB;
  for (int i = 1; i+k-1 < 2*n; i++) {
    int j = i+k-1;
    totalA = totalA - a[i-1] + a[j];
    
    if (os.order_of_key(b[i-1]+1) < l) {
      if (k > l) totalB += *os.find_by_order(l);
      totalB -= b[i-1];
    }

    os.erase(os.find_by_order(os.order_of_key(b[i-1])));

    if (os.order_of_key(b[j]+1) < l) {
      if (k > l-1) totalB -= *os.find_by_order(l-1);
      totalB += b[j];
    }
    os.insert(b[j]);

    if (0 < i && j < n-1) continue;
    if (n < i && j < 2*n-1) continue;
    ans = max(ans, totalA + totalB);
  }
  cout << ans << "\n";

  return 0;
}