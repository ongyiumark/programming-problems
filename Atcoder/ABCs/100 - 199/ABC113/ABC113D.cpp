/*
  Use DP. 
  dp[w][h] = a*dp[w-1][h-1] + b*dp[w+1][h-1] + c*dp[w][h]
    where a is the number of valid horizontal lines on row h that connects to w-1 to w,
    b is the number of valid horizontal lines on row h that connects to w to w+1,
    c is the number of valid horizontal lines on row h that doesn't have a connection to both w-1 and w+1.

  We can count a, b, c by trying all 2^(w-1) possibilities.
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

const ll MOD = 1e9+7;

ll dp[10][105];
ll h, w, k; 

ll solve(int x, int y){
  ll &ans = dp[x][y];
  if (ans != -1) return ans;
  if (y == 0) {
    if (x != 1) return ans = 0;
    return ans = 1;
  }
  ans = 0;

  ll l, r, up;
  l = r = up = 0;
  for (int mask = 0; mask < (1 << (w-1)); mask++){
    vector<bool> tmp;
    for (int i = 0; i < w-1; i++){
      if ((1<<i)&mask) tmp.push_back(1);
      else tmp.push_back(0);
    }

    bool valid = true;
    for (int i = 0; i < w-2; i++){
      if (tmp[i] && tmp[i+1]) valid = false;
    }
    if (!valid) continue;

    bool valup = true;
    if (x-2 >= 0 && x-2 < w-1 && tmp[x-2]) l++, valup = 0;
    if (x-1 >= 0 && x-1 < w-1 && tmp[x-1]) r++, valup = 0;
    if (valup) up++;
  }

  if (x > 1) ans += l*solve(x-1, y-1)%MOD;
  if (x < w) ans += r*solve(x+1, y-1)%MOD;
  ans += up*solve(x, y-1)%MOD;
  ans %= MOD;
  return ans;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> h >> w >> k;
  if (w == 1) {
    cout << 1 << endl;
    return 0;
  }
  memset(dp, -1, sizeof dp);
  cout << solve(k, h) << endl;
  return 0;
}
