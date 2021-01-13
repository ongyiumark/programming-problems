/*
  Count how many a+b <= n such that each bit of b is smaller or equal to the corresponding bit of a.
  Digit DP.
  dp[i][carry][ok]
  i is the ith bit. 
  carry keeps track if theres a carry in the addition.
  ok is 0 if the sum is less than n.
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

const ll MOD = 1e9+7;
ll dp[63][2][2];
ll n;

ll solve(int i, int carry, int ok){
  ll ret = dp[i][carry][ok];
  if (ret != -1) return ret;
  if (i == 62) return dp[i][carry][ok] = (carry == 0 && ok == 0);

  int bit = (n>>i)&1;
  ret = 0;
  for (int a = 0; a <= 1; a++){
    for (int b = 0; b <= a; b++){
      int currbit = (a+b+carry)%2;
      int ncarry = (a+b+carry)/2;
      int nok = ok;
      if (currbit > bit) nok = 1;
      if (currbit < bit) nok = 0;
      ret += solve(i+1, ncarry, nok);
      ret %= MOD;
    }
  }
  return dp[i][carry][ok] = ret;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  memset(dp, -1, sizeof dp);
  cout << solve(0, 0, 0) << endl;

  return 0;
}
