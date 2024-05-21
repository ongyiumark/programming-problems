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

const int MOD = 1e9+7;
const int N = 51;
int n;

ll memo[N][N][N*N];
// i = index, j = no. matches, k = oddness
ll solve(int i, int j, int k) {
  if (j < 0 || k < 0) return 0;
  
  ll &ans = memo[i][j][k];
  if (i == 0) return ans = (k == 0 && j == 0);
  if (ans != -1) return ans;
  // (i-1)-(j-2) = i-j+1 
  // L_i with R_<i and R_i with L_<i
  ll ans1 = solve(i-1, j-2, k-2*(i-j+1))*(i-j+1)*(i-j+1)%MOD;

  // (i-1)-(j-1) = i-j
  // L_i with R_<i and R_i with R_>i, vice versa
  ll ans2 = solve(i-1, j-1, k-2*(i-j))*(i-j)*2%MOD;

  // (i-1)-(j-1)
  // L_i with R_i
  ll ans3 = solve(i-1, j-1, k-2*(i-j));

  // (i-1)-j
  // L_i with R_>i and R_i with L_>i
  ll ans4 = solve(i-1, j, k-2*(i-j-1));
  ans = ans1 + ans2 + ans3 + ans4;
  ans %= MOD;
  return ans;
}

int main(){
  cin.tie(0)->sync_with_stdio(false);
  
  int k; cin >> n >> k;
  memset(memo, -1, sizeof memo);
  cout << solve(n, n, k) << "\n";

  return 0;
}
