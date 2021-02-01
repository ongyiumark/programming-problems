/*
  DP[i][2] where the ith number goes over and goes under.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

string s;
const int N = 1e6+5;
int dp[N][2];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s;
  int n = s.size();
  int carry = 0;
  int ans = 0;

  dp[0][0] = s[0]-'0';
  dp[0][1] = 11-(s[0]-'0');
  for (int i = 1; i < n; i++){
    int curr = s[i]-'0';
    dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + curr;
    dp[i][1] = min(dp[i-1][0]+11-curr, dp[i-1][1]+9-curr);
  }

  cout << min(dp[n-1][0], dp[n-1][1]) << endl;
  return 0;
}
