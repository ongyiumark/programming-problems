/*
  First, we root the tree to make it easier to work with.
  Let's focus on the root.
  There are two possibilities:
    1. In the connected component of the root, it's all batteries.
    2. In the connected component of the root, there are some computers and the sum is negative.
  All other connected components are valid.

  Define DP1[u][k] to be the minimum sum of the connected component of u given that its all batteries, 
    and there are k connected components (i.e., there are k-1 other valid connected components).
  
  Define DP2[u][k] to be the minimum sum of the connected component of u, which may not be valid,
    but the other k-1 connected components are valid.
  We know this is valid if the sum is negative.

  If node u is a battery: 
    We can add it to another connected component with all batteries
    DP1[u][i+j-1] := minimum over i, j of DP1[u][i] + DP1[v][j]

    We can also have it by itself if v has a valid j split (all batteries or not).
    DP1[u][i+j] := minimum over i, j of DP1[i]

  If node u is not necessarilly a battery:
    We can add it to another connected component with all batteries or a connected component that may not be valid.
    DP2[u][i+j-1] := minimum over i, j of min(DP2[u][i] + DP1[v][j], DP2[u][i] + DP2[v][j])

    We can have it by itself if v has a valid j split (all batteries or not)
    DP1[u][i+j] := minimum over i, j of DP1[i]
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
vector<int> graph[N];
ll A[N];
int n;

vector<ll> dp[2][N];

vector<ll> solve(int u, int v, bool allBat){
  vector<ll> og = (allBat ? dp[0][u] : dp[1][u]);

  int a = og.size();
  int b = dp[0][v].size();
  vector<ll> res(a+b-1);
  fill(res.begin(), res.end(), INF);

  for (int i = 0; i < a; i++){
    if (og[i] == INF) continue; 
    for (int j = 0; j < b; j++){
      if (dp[0][v][j] != INF) {
        // Combine with one of the all batteries
        res[i+j-1] = min(res[i+j-1], og[i]+dp[0][v][j]);

        // Disconnect
        res[i+j] = min(res[i+j], og[i]);
      }

      // Combine with not all batteries, and not necessarily valid.
      if (dp[1][v][j] != INF && !allBat) res[i+j-1] = min(res[i+j-1], og[i]+dp[1][v][j]);

      // Disconnect if not all batteries is negative.
      if (dp[1][v][j] < 0) res[i+j] = min(res[i+j], og[i]);
    }
  }
  return res;
}

void dfs(int u, int p){
  dp[0][u].resize(2);
  dp[1][u].resize(2);
  
  dp[0][u][0] = dp[1][u][0] = INF;

  // Connected to u are all battery
  dp[0][u][1] = (A[u] > 0 ? A[u] : INF);
  // Connected to u may not be valid, but everything that's not connected is valid.
  dp[1][u][1] = A[u];

  for (int v : graph[u]){
    if (v == p) continue;
    dfs(v,u);
    dp[0][u] = solve(u,v,true);
    dp[1][u] = solve(u,v,false);
  }
}

int answer(){
  for (int i = 0; i <= n; i++){
    // Node 0 is connected to all batteries with i connected components.  
    if (dp[0][0][i] < INF) return i-1;
    // Note 0 is connected to some computers with i connected components.
    if (dp[1][0][i] < 0) return i-1;
  }
  return -1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];
  for (int i = 0; i < n-1; i++){
    int u, v; cin >> u >> v;
    u--; v--;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  dfs(0,-1);

  cout << answer() << endl;
  return 0;
}
