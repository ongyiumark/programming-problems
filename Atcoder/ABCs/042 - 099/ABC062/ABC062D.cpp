/*
  We can split the sequence into 2. 
  Get the sum of the largest n in the left and get the sum of the smallest n in the right.
  Simply try all possible splits. We can split at [N,2*N).

  To get the sum of the largest/smallest n, we can use a priority queue.
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5;
ll a[3*N];
ll ltotals[N+1];
ll rtotals[N+1];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  for (int i = 0; i < 3*n; i++){
    cin >> a[i];
  }
  ll left_total = 0;
  ll right_total = 0;
  priority_queue<ll, vector<ll>, greater<ll>> lpq;
  priority_queue<ll> rpq;
  for (int i = 0; i < n; i++){
    lpq.push(a[i]);
    left_total += a[i];
  }

  ltotals[0] = left_total;
  for (int i = n; i < 2*n; i++){
    lpq.push(a[i]);
    left_total += a[i];
    left_total -= lpq.top();
    lpq.pop();
    ltotals[i-n+1] = left_total;
  }

  for (int i = 3*n-1; i >= 2*n; i--){
    rpq.push(a[i]);
    right_total += a[i];
  }

  rtotals[n] = right_total;
  for (int i = 2*n-1; i >= n; i--){
    rpq.push(a[i]);
    right_total += a[i];
    right_total -= rpq.top();
    rpq.pop();
    rtotals[i-n] = right_total;
  }

  ll ans = -1e18;
  for (int i = 0; i <= n; i++){
    ans = max(ans, ltotals[i]-rtotals[i]);
  }
  cout << ans << endl;
  return 0;
}
