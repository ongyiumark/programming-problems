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

const int N = 1e5+5;
int dp[N][55];
string s;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k, g1, g2,g3;
  cin >> n >> k >> g1 >> g2 >> g3;
  cin >> s;
  dp[0][0] = 0;

  
  return 0;
}
