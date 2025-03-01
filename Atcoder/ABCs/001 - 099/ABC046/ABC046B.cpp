#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int n, k;

const int N = 1001;
int dp[N][N];

int solve(int i, int col){
  if (dp[i][col] != -1) return dp[i][col];
  if (i == 0) return dp[i][col] = 1;
  
  int total = 0;
  for (int x = 0; x < k; x++){
    if (x == col) continue;
    total += solve(i-1, x);
  }
  return dp[i][col] = total;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;

  memset(dp, -1, sizeof dp);
  int ans = 0;
  for (int i = 0; i < k; i++){
    ans += solve(n-1, i);
  }
  cout << ans << endl;
  return 0;
}
