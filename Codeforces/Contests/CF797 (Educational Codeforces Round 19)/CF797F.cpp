/*
  DP[i][j] for first i holes and first j mice.
  
  Naive solution: O(n^2 m)
  With RMQ: O(nlgn m)
  Maintain minimum with deque: O(nm)
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

const int N = 5005;
const ll INF = 1e18;
ll dp[2][N];
vector<int> x(N), p(N), c(N);
vector<pair<int,int>> pc(N);
vector<ll> S(N), arr(N);
deque<pair<ll,int>> dq;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m; cin >> n >> m;
  memset(dp, 31, sizeof dp);

  for (int i = 0; i < n; i++) cin >> x[i];
  int cap = 0;
  for (int i = 0; i < m; i++) {
    cin >> p[i] >> c[i];
    pc[i] = {p[i], c[i]};
    cap += c[i];
  }

  sort(x.begin(), x.begin()+n);
  sort(pc.begin(), pc.begin()+m);

  for (int i = 0; i < m; i++) {
    p[i] = pc[i].first;
    c[i] = pc[i].second;
  }

  if (n > cap) {
    cout << -1 << endl;
    return 0;
  }

  for (int j = 0; j < n; j++) {
    if (c[0] >= j+1) {
      dp[0][j] = (ll)abs(p[0]-x[j]);
      if (j > 0) dp[0][j] += dp[0][j-1];
    }
  }

  for (int i = 1; i < m; i++) {
    for (int j = 0; j < n; j++) {
      S[j] = abs(p[i]-x[j]);
      if (j > 0) S[j] += S[j-1];
      dp[i%2][j] = INF;

      arr[j] = dp[(i-1)%2][j]-S[j];
    }
 
    
    for (int j = 0; j < n; j++) {
      if (c[i] >= j+1) dp[i%2][j] = min(dp[i%2][j], S[j]);
      while (!dq.empty() && dq.back().first >= arr[j]) dq.pop_back();
      if (!dq.empty() && arr[j] <= dq.front().first) dq.push_front({arr[j], j});
      else dq.push_back({arr[j], j});

      while(!dq.empty() && dq.front().second < j-c[i]) dq.pop_front();
    
      dp[i%2][j] = min(dp[i%2][j],dq.front().first+S[j]);
    }

    while(!dq.empty()) dq.pop_front();
  }
  
  cout << dp[(m-1)%2][n-1] << endl;
  return 0;
}
