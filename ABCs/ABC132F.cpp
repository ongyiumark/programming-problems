/*
  Take advantage of the fact that there are only 2*sqrt(n) values for floor(n/i).
  
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MOD = 1e9+7;
const int N = 5e5;

ll dp[101][N];
ll pref[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;

  vector<int> floors;

  for (int i = 1; i*i <= n; i++){
    floors.push_back(i);
    if (i != n/i) floors.push_back(n/i);
  }

  sort(floors.begin(), floors.end(), greater<int>());
  int fsz = floors.size();
  for (int i = 0; i < fsz; i++){
    int curr = floors[i];
    dp[1][i] = n/(curr) - n/(curr+1);
  }  

  for (int i = 2; i <= k; i++){
    pref[0] = dp[i-1][0]%MOD;
    for (int j = 1; j < fsz; j++){
      pref[j] = (pref[j-1]+dp[i-1][j])%MOD;
    }

    for (int j = 0; j < fsz; j++){
      int until = floors[j];
      ll multi =  n/(until) - n/(until+1);
      dp[i][j] = pref[fsz-1-j]*multi%MOD;
    }

  }

  ll ans = 0;
  for (int i = 0; i < fsz; i++){
    ans = (ans + dp[k][i])%MOD;
  }

  cout << ans << endl;
  return 0;
}
