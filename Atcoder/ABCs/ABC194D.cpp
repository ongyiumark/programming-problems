/*
  Let dp[x] be the expected number of moves to visit x nodes.
  We want dp[n].
  dp[x] = dp[x-1] + (nC1) * sum of i * ((x-1)/n)^(i-1) (1 - (x-1)/n)
    First, we choose 1 node to be our last node visited (nC1).
    Then, since x-1 nodes are already visited, we can use those x-1 nodes as filler.
    Then, we multiply the probability with the number of moves to get expected value.
  
  Notice that the summation is a combination of an arithmetic and geometric series. We can derive a formula for that.
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

const int N = 1e5;
ld dp[N+5];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  dp[1] = 0;
  for (int i = 2; i <= n; i++){
    dp[i] = dp[i-1] + (ld)1/(n-i+1);
  }
  cout << fixed << setprecision(10) << n*dp[n] << endl;
  return 0;
}
