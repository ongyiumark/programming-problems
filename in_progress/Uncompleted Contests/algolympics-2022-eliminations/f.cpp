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

const int N = 1e3+5;
int dp[N][N][2];
string A, B;

int solve(int l, int r, bool flag){
  int &ans = dp[l][r][flag];
  if (ans != -1) return ans;
  if (l == r) return ans = (A[l]==B[l]);
  if (l > r) return ans = 0; 
  if (flag){
    return ans = (A[l]==B[r])+(A[r]==B[l])+solve(l+1,r-1,1);
  }
  ans = max({
    (A[r]==B[r])+solve(l,r-1, flag),
    (A[l]==B[l])+solve(l+1,r, flag),
    (A[l]==B[r])+(A[r]==B[l])+solve(l+1,r-1,1)
   });
  
  return ans;
}

void testcase(){
  cin >> A >> B;
  int n = A.size();
  memset(dp, -1, sizeof dp);
  cout << solve(0, n-1, 0) << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T; cin >> T;
  for (int i = 0; i < T; i++){
    testcase();
  }
  return 0;
}
