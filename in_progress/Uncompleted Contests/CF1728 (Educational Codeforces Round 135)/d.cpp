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
const int N = 2e3+5;
short dp[N][N][2][26];

short solve(int l, int r, int player, char ch) {
  if (dp[l][r][player][ch-'a'] != -1) return dp[l][r][player][ch-'a'];
  short &ans = dp[l][r][player][ch-'a'];
  if (r - l == 1) {
    if (s[l] == s[r]) return 1;
    else return 0;
  }

  if (player == 0) ans = min(solve(l+1,r,1-player, s[l]), solve(l, r-1, 1-player, s[r]));
  else ans = max(solve(l+1,r,1-player, s[l]), solve(l, r-1, 1-player, s[r]));
  
  if (ans == 1) {
    if (player == 0) {

    }
    else if (player == 1) {
      if (s[l] < ch && solve(l+1,r,1-player, s[l]) == 1) ans = 2;
      else if (s[r] < ch && solve(l, r-1, 1-player, s[r])) ans = 2;
      else if (ch < s[l] && ch < s[r]) ans = 0;
      else ans = 1;
    }
  }
  return ans;
}
void testcase() {
  cin >> s;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < 26; k++) {
        dp[i][j][0][k] = dp[i][j][1][k] = -1;
      }

    }
  }

  int ans = solve(0, n-1, 0, 0);
  if (ans == 0) cout << "Alice";
  else if (ans == 1) cout << "Draw";
  else cout << "Bob";
  cout << endl;
  


}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--) {
    testcase();
  }
  
  return 0;
}
