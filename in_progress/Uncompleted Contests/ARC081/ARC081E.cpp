/*
  We can first compute for the length of the answer with DP.
  For every index i, and for every letter c, we precompute the next occurence of c from i onward.
  Then, let DP[i][c] denote the length of a subsequence not in A[i:] that starts with c.
    DP[i][c] = min(DP[next_occur[i][c]+1][ch]) for all ch.

  To get the actual string, go through each index i, and each letter c, and save the first c such that
    DP[i][c] = answer.
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

const int N = 2e5+5;
int next_char[N][26];
int dp[N][26];
string A;
int n;

int solve(int i, int j) {
  int &ans = dp[i][j];
  if (ans != -1) return ans;
  if (i == n) return ans = 1;

  ans = 1e9;
  if (next_char[i][j] == n) return ans = 1;
  for (int k = 0; k < 26; k++) {
    ans = min(ans, 1+solve(next_char[i][j]+1, k));
  }
  return ans;
}

string get_string(int i, int len) {
  if (i == n) return string(len, 'a');
  for (int j = 0; j < 26; j++) {
    if (solve(i, j) == len){
      return string(1,'a'+j) + get_string(next_char[i][j]+1, len-1);
    }
  }
  return "";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> A;

  n = A.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 26; j++) {
      next_char[i][j] = n;
    }
  }

  // Compute the first appearance of a letter from i onwards.
  int curr[26];
  for (int i = 0; i < 26; i++) curr[i] = n;
  for (int i = n; i >= 0; i--) {
    curr[A[i]-'a'] = i;
    for (int j = 0; j < 26; j++) {
      next_char[i][j] = curr[j];
    }
  }

  memset(dp, -1, sizeof dp);
  int ans = 1e9;
  for (int j = 0; j < 26; j++) {
    ans = min(ans, solve(0, j));
  }

  cout << get_string(0, ans) << endl;
  return 0;
}
