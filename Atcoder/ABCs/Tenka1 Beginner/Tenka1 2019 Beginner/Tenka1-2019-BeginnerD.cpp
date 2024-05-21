/*
  Notice that we only need to check if the longest side is less than the sum of the other 2.
    That is, if a < b < c, then we only need to check a + b > c.
  
  Consider counting the complement. Notice also that if a + b <= c, then c is the longest side.
  This is easier to count because we can WLOG suppose that R is the longest side. 
    Then, multiply the answer by 3 at the end. 
  
  We can't do this if we count a+b > c directly because a+b > c doesn't imply a,b < c.

  Notice also that a + b <= c is equivalent to a+b+c <= 2*c. We can precompute for a+b+c.
  So, we can do DP where DP[pos][hi] is the number of ways such that pos+1 onwards can satisfy total <= 2*hi.
  The recursion is DP[pos][hi] = DP[pos+1][hi+A[pos]] + 2*DP[pos+1][hi].
    (Either we color the current integer with 'hi' or color it with the other 2).
  
  Now multiplying this by 3 would actually double count the case where the hi = total/2 and one of the other colors is 0.
  For example, consider the following case:
    R = total/2, B = total/2, G = 0
  This would be counted when R is the highest as well as when B is the highest.

  We can count the number of ways this occurs with a similar DP.
  DP2[pos][hi] is the number of ways such that pos+1 onwards can satisfy hi = total/2 and one other color is 0.
  The recursion is DP2[pos][hi] = DP2[pos+1][hi+A[pos]] + DP2[pos+1][hi].
    (Either we color the current integer with 'hi' or color it with the other color that isn't 0).
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

const ll MOD = 998244353;
const int N = 305;
int A[N];
int pref[N];
int n;

ll dp[N][N*N];
ll dp2[N][N*N];

ll modpow(ll b, ll e){
  ll ans = 1;
  while (e > 0){
    if (e&1) ans = ans*b%MOD;
    e >>= 1;
    b = b*b%MOD;
  }
  return ans;
}

ll solve(int pos, int hi){
  ll &ans = dp[pos][hi];
  if (ans != -1) return ans;
  if (pos == n) return ans = (pref[n-1] <= 2*hi);
  ans = 0;
  ans += solve(pos+1, hi+A[pos]);
  ans += 2*solve(pos+1, hi);
  ans %= MOD;
  return ans;
}

ll solve2(int pos, int hi){
  ll &ans = dp2[pos][hi];
  if (ans != -1) return ans;
  if (pos == n) return ans = (pref[n-1] == 2*hi);
  ans = 0;
  ans += solve2(pos+1, hi+A[pos]);
  ans += solve2(pos+1, hi);
  ans %= MOD;
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];
  for (int i = 0; i < n; i++) {
    pref[i] = A[i];
    if (i > 0) pref[i] += pref[i-1];
  }

  memset(dp, -1, sizeof dp);
  memset(dp2, -1, sizeof dp2);
  ll ans = modpow(3,n);
  ans -= 3*solve(0,0);
  ans += 3*solve2(0,0);
  ans %= MOD;
  if (ans < 0) ans += MOD;
  cout << ans << endl;
  return 0;
}
