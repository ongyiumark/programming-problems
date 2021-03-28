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

int x, y;
string s;
int n;
const int N = 1000;
ll dp[1000][2];
bool seen[1000][2];
// 0 : J, 1 : c
ll solve(int i, bool c){
  if (n == 1) return 0;
  if (i >= n) return 0;
  if (seen[i][c]) return dp[i][c];
  seen[i][c] = 1;
  if (s[i] != '?' && s[i] != (c ? 'C' : 'J')) {
    return dp[i][c] = 1e9;
  }
  
  if (c) return dp[i][c] = min(x+solve(i+1,0), solve(i+1,1));
  else return dp[i][c] = min(solve(i+1,0), y+solve(i+1,1));
}
void testcase(){
  cin >> x >> y >> s;
  n = s.size();
  memset(dp, 0, sizeof dp);
  memset(seen, 0, sizeof seen);
  cout << min(solve(0,0), solve(0,1)) << endl; 
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  for (int x = 1; x <= t; x++){
    cout << "Case #" << x << ": ";
    testcase();
  }
  return 0;
}
