/*
  You can brute force since the bounds are small, but digit DP is the smart answer.
  Keep track of which digits have been placed.
    You can do this with a lot 3 booleans, or a bitmask.
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

string s;
int m;
const int N = 15;
int dp[N][2][8];

int solve(int i, bool above, int mask){
  int& ans = dp[i][above][mask];
  if (ans != -1) return ans;
  if (i == m) return ans = int(mask == 7);
  
  ans = 0;
  for (int x : {0,3,5,7}){
    int tmpmask = 0;
    if (x == 3) tmpmask = (1<<0);
    if (x == 5) tmpmask = (1<<1);
    if (x == 7) tmpmask = (1<<2);

    int cs = s[i]-'0';

    if (x == 0 && mask != 0) continue;
    if (!above){
      if (cs < x) continue;
      if (cs == x) ans += solve(i+1, 0, tmpmask|mask);
      else ans += solve(i+1, 1, tmpmask|mask); 
    }
    else {
      ans += solve(i+1, 1, tmpmask|mask);
    }
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> s;
  m = s.size();
  memset(dp, -1, sizeof dp);

  cout << solve(0,0,0) << endl;
  return 0;
}
