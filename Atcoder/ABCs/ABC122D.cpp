/*
  We just need to keep track of the last 3 letters.
  We can't have "ACG", "GAC", or "AGC".
  Then, when adding a letter, we cant have "AGGC", "AGTC", or "ATGC".
  
  This can be solved with DP[i][a][b][c] which counts the number of valid string of length i
    with last three letters abc.
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

// A, G, C, T
ll dp[105][4][4][4];
unordered_set<string> illegal = {"ACG", "GAC", "AGC", "AGGC", "AGTC", "ATGC"};
string p[4] = {"A", "G", "C", "T"};

bool threeCheck(int a, int b, int c){
  string s = p[a] + p[b] + p[c];
  if (illegal.find(s) != illegal.end()) return false;
  return true;
}

bool fourCheck(int k, int a, int b, int c){
  string s = p[k] + p[a] + p[b] + p[c];
  if (illegal.find(s) != illegal.end()) return false;
  return true;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  
  memset(dp, 0, sizeof dp);
  for (int a = 0; a < 4; a++){
    for (int b = 0; b < 4; b++){
      for (int c = 0; c < 4; c++){
        dp[3][a][b][c] = threeCheck(a,b,c);
      }
    }
  }
  
  for (int i = 4; i <= n; i++){
    for (int a = 0; a < 4; a++){
      for (int b = 0; b < 4; b++){
        for (int c = 0; c < 4; c++){
          if (!threeCheck(a,b,c)) continue;
          for (int k = 0; k < 4; k++){
            if (!fourCheck(k,a,b,c)) continue;
            dp[i][a][b][c] += dp[i-1][k][a][b];
            dp[i][a][b][c] %= MOD;
          }
        }
      }
    }
  }

  ll ans = 0;
  for (int a = 0; a < 4; a++){
    for (int b = 0; b < 4; b++){
      for (int c = 0; c < 4; c++){
        ans += dp[n][a][b][c];
      }
    }
  }
  cout << ans % MOD << endl;
  return 0;
}
