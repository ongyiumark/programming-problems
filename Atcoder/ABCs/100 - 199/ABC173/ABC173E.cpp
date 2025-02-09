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

const ll MOD = 1e9+7;
const ll INF = 1e18;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, k; cin >> n >> k;
  vector<ll> A(n);
  for (int i = 0; i < n; i++) cin >> A[i];

  sort(A.rbegin(), A.rend(), [](const ll left, const ll right) {
    return abs(left) < abs(right);
  });

  int neg = 0;
  for (int i = 0; i < n; i++) {
    if (A[i] < 0) neg++;
  }

  ll small_pos = -1;
  ll small_neg = -1;
  ll total = 1;
  for (int i = 0; i < k; i++) {
    total *= A[i];
    total %= MOD;

    if (A[i] >= 0) small_pos = i;
    if (A[i] <= 0) small_neg = i;
  }

  if (total >= 0 || n == k) {
    if (total < 0) total += MOD;
    cout << total << "\n";
    return 0;
  }



  ll next_pos = -1;
  ll next_neg = -1;
  for (int i = k; i < n; i++) {
    if (next_pos == -1 && A[i] >= 0) next_pos = i;
    if (next_neg == -1 && A[i] <= 0) next_neg = i;
  }

  if (small_pos == -1 && next_pos == -1) {
    // all negative 
    // get minimim
    total = 1;
    for (int i = n-1; i >= n-k; i--) {
      total *= A[i];
      total %= MOD;
    }

    if (total < 0) total += MOD;
    cout << total << "\n";

    return 0;
  }

  if ((small_neg == -1 || next_pos == -1) && (small_pos == -1 || next_neg == -1)) {
    if (total < 0) total += MOD;
    cout << total << "\n";
    return 0;
  }
  if ((small_neg == -1 || next_pos == -1)) {
    // replace smallest pos with next neg
    total = 1;
    for (int i = 0; i < k; i++) {
      if (i == small_pos) continue;
      total *= A[i];
      total %= MOD;
    }
    total *= A[next_neg];
    total %= MOD;
    cout << total << "\n";
    return 0;
  }

  if((small_pos == -1 || next_neg == -1)) {
    // replace smallest neg with next pos
    total = 1;
    for (int i = 0; i < k; i++) {
      if (i == small_neg) continue;
      total *= A[i];
      total %= MOD;
    }
    total *= A[next_pos];
    total %= MOD;
    cout << total << "\n";
    return 0;
  }
  

  if (A[small_pos] * A[next_pos] >= A[small_neg] * A[next_neg]) {
    // replace smallest neg with next pos
    total = 1;
    for (int i = 0; i < k; i++) {
      if (i == small_neg) continue;
      total *= A[i];
      total %= MOD;
    }
    total *= A[next_pos];
    total %= MOD;
  }
  else {
    // replace smallest post with next neg
    total = 1;
    for (int i = 0; i < k; i++) {
      if (i == small_pos) continue;
      total *= A[i];
      total %= MOD;
    }
    total *= A[next_neg];
    total %= MOD;
  }
  cout << total << "\n";

  return 0;
}
