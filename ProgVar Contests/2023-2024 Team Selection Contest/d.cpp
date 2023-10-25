#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


vector<int> memo;
vector<vector<int>> occur;
vector<vector<bool>> valid;
int n, k;

int solve(int u) {
  if (memo[u] != -1) return memo[u];
  int &ans = memo[u];

  ans = 1;
  for (int v = 0; v < k; v++) {
    if (!valid[u][v]) continue;
    ans = max(ans, 1+solve(v));
  }
  
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;
  vector<string> words(n);
  for (int i = 0; i < n; i++) cin >> words[i];
  memo.assign(k, -1);
  occur.assign(n, vector<int>(k, 0));
  valid.assign(k, vector<bool>(k, 0));

  for (int j = 0; j < k; j++) {
    for (int i = 0; i < n; i++) {
      occur[i][words[i][j]-'A'] = j;
    }
  }
  for (int a = 0; a < k; a++) {
    for (int b = 0; b < k; b++) {
      bool is_valid = true;
      for (int i = 0; i < n; i++) {
        is_valid &= (occur[i][a] < occur[i][b]);
      }
      valid[a][b] = is_valid;
    }
  }

  int ans = 0;
  for (int i = 0; i < k; i++) {
    ans = max(solve(i), ans);
  }
  cout << ans << "\n";
  return 0;
}
