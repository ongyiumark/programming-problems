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

#define int ll

const int N = 2e4+5;
const int INF = 1e9;
int a[N];
int dp[2][N];

vector<int> aLo, w;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, x; cin >> n >> x;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a+n);

  int hi = -INF;

  // Keep only items t[i] < x
  for (int i = 0; i < n; i++) {
    if (a[i] <= x) aLo.push_back(a[i]);
    else hi = max(hi, a[i]);
  }

  int m = aLo.size();
  if (m == 0) {
    cout << hi << endl;
    return 0;
  }
  // Edge cases
  if (m <= 2) {
    cout << max({aLo[m-1],hi}) << endl;
    return 0;
  }

  if (m <= 4) {
    cout << max({x+1, hi}) << endl;
    return 0;
  }

  
  int T = 0;
  for (int i = 4; i < m; i++) {
    w.push_back(x-a[i]+1);
    T += w[i-4];
  }

  if (m-4 == 1) {
    cout << max(x+1+w[0], hi) << endl;
    return 0;
  }
  
  int S = 0;
  // Solve the largest subset sum S such that S <= T/2
  int b = 0;
  int wBar = 0;
  int C = T/2;
  sort(w.begin(), w.end());
  for (int i = 0; i < m-4 && wBar <= C; i++) {
    wBar += w[i];
    b = i+1;
  }
  wBar -= w[b-1];
  //cout << b << endl;

  int start = C-x+1;
  for (int u = C-x+1; u <= C; u++) dp[(b-1)%2][u-start] = 0; 
  for (int u = C+1; u <= C+x; u++) dp[(b-1)%2][u-start] = 1;
  dp[(b-1)%2][wBar-start] = b;
  
  for (int t = b; t <= m-4; t++) {
    for (int u = C-x+1; u <= C+x; u++) dp[t%2][u-start] = dp[(t-1)%2][u-start];
    for (int u = C-x+1; u <= C; u++) {
      int v = u + w[t-1];
      dp[t%2][v-start] = max(dp[t%2][v-start], dp[(t-1)%2][u-start]);
    }
    
    for (int u = C+w[t-1]; u >= C+1; u--) {
      for (int j = dp[t%2][u-start]-1; j >= dp[(t-1)%2][u-start]; j--) {
        int v = u-w[j-1];
        dp[t%2][v-start] = max(dp[t%2][v-start],j);
      }
    }
  }
  
  for (int u = C; u >= C-x+1; u--) {
    //cout << i << " " << dp[(m-4)%2][i-start] << endl;
    if (dp[(m-4)%2][u-start] > 0) {
      
      S = u;
      break;
    }
  }

  cout << max({x+1+T-S, hi}) << endl;
  
  
  return 0;
}
