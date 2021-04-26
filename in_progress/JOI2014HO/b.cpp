/*
  Greedily pick the most expensive snacks first. Try all numbers of snacks. O(M)
  For each number of snack, we can determine the minimum price to box that number.
    Modified knapsack problem.
    We only care about capacities up to M.
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

int m, n;
const int M = 1e4+5;
int P[M];
int prefP[M];
const int N = 500;
pii CE[N];

int dp[M];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> m >> n;
  for (int i = 0; i < m; i++) cin >> P[i];
  for (int i = 0; i < n; i++){
    int c, e; cin >> c >> e;
    CE[i] = {c,e};
  }

  sort(P, P+m, greater<int>());
  sort(CE, CE+n, [](const pii &left, const pii &right){
    return (ld)left.second/left.first < (ld)right.second/right.first;
  });

  prefP[0] = P[0];
  for (int i = 1; i < m; i++){
    prefP[i] = P[i] + prefP[i-1];
  }

  memset(dp, 63, sizeof dp);
  dp[0] = 0;
  for (int i = 0; i < n; i++){
    for (int j = M-1; j >= 0; j--){
      if (dp[j] < 1e9){
        int idx = min(j+CE[i].first, M-1);
        dp[idx] = min(dp[idx], dp[j]+CE[i].second); 
      }
    }
  }
  for (int j = M-1; j > 0; j--){
    dp[j-1] = min(dp[j], dp[j-1]);
  }

  int ans = 0;
  for (int i = 0; i < m; i++){
    ans = max(ans,prefP[i]-dp[i+1]);
  }
  cout << ans << endl;
  return 0;
}
