/*
  A card x is necessary if, excluding x from the set, we can obtain a sum that is 
  grater than or equal to k-x and less than k.
  This can be done in O(NK) with knapsack dp.

  Notice that if x is unnecessary, then everything less than x is also unnecessary.
  We can binary search.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 5001;
int dp[N];
int a[N];
int n, k;

bool valid(int x){
  memset(dp, 0, sizeof dp);
  dp[0] = 1;
  for (int i = 0; i < n; i++){
    if (i == x) continue;
    for (int j = k; j >= 0; j--){
      if (!dp[j]) continue;
      dp[min(j + a[i], k)] += dp[j];
    }
  }
  for (int i = max(k-a[x], 0); i < k; i++){
    if (dp[i]) return false;
  }
  return true;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }

  sort(a, a+n);
  int lo = 0;
  int hi = n-1;
  int ans = -1;
  while(lo <= hi){
    int mid = hi-(hi-lo)/2;
    if (valid(mid)) {
      ans = mid;
      lo = mid+1;
    }
    else hi = mid-1;
  }

  cout << ans+1 << endl;
  return 0;
}
