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

const int N = 50;
vector<ll> A(N);
int n; 
ll x;
map<pair<ll,ll>, ll> dp;

ll solve(ll i, ll j) {
  if (dp.count({i,j}) > 0) return dp[{i,j}];
  
  ll &ans = dp[{i,j}];
  if (i == -1) return ans = 1;
  
  ll pos = (i < n-1 ? A[i+1]/A[i] : 1e18);


  ll curr_sum = j+x;
  ll lo = x/A[i]*A[i];
  ll hi = (x+A[i]-1)/A[i]*A[i];

  ll lo_val = (lo-curr_sum)/A[i];
  if (-pos < lo_val && lo_val < pos) ans += solve(i-1, lo-x);

  ll hi_val = (hi-curr_sum)/A[i];
  if (-pos < hi_val && hi_val < pos && hi != lo) ans += solve(i-1, hi-x);

  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n >> x;
  for (int i = 0; i < n; i++) cin >> A[i];
  cout << solve(n-1, -x) << "\n";
  return 0;
}
