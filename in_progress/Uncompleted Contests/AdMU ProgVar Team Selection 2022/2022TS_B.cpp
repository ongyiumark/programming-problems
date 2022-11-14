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

const int N = 2e3+5;
const int INF = 1e9;
ll dp[10][N];
ll C[N];
int G[N];
vector<ll> genres[N];
vector<ll> pref[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n,k; cin >> n >> k;
  int maxG = -INF;
  for (int i = 0; i < n; i++) {
    cin >> C[i] >> G[i];
    G[i]--;
    genres[G[i]].push_back(C[i]);
    maxG = max(maxG, G[i]);
  }

  for (int g = 0; g <= maxG; g++) {
    sort(genres[g].begin(), genres[g].end(), greater<ll>());
    int m = genres[g].size();
    vector<ll>(m,0).swap(pref[g]);
    for (int i = 0; i < m; i++) {
      pref[g][i] = genres[g][i];
      if (i > 0) pref[g][i] += pref[g][i-1];
    }
  }

  memset(dp, 0, sizeof dp);
  int m = genres[0].size();
  for (int i = 1; i <= m; i++) {
    if (i > k) break;
    dp[0][i] = pref[0][i-1]+(i-1)*(i);
  }

  for (int g = 1; g <= maxG; g++) {
    m = genres[g].size();
    for (int i = 0; i <= k; i++) {
      dp[g][i] = max(dp[g][i], dp[g-1][i]);
      for (int x = 1; x <= m; x++) {
        if (i+x > k) break; 
        dp[g][i+x] = max(dp[g][i+x], dp[g-1][i]+pref[g][x-1]+(x-1)*x);
      }
    }
  }

  /*  
  for (int i = 0; i < 3; i++) {
    cout << i+1 << ": ";
    for (int v : pref[i]) {
      cout << v <<  " "; 
    }
    cout << endl;
  }*/

  cout << dp[maxG][k] << endl;
  return 0;
}
