/*
  We can solve the problem without blocking with DP.
  dp[u] = 1 + sum of dp[v]*prob[v].

  Now for the blocking, we can try blocking every edge and running the DP again, but that's too slow.
  Instead, we can consider blocking an edge that starts from node x.
  The optimal edge to block is the node v such that dp[v] is maximum. (Make sure that there's another edge available)

  I tried using a hashmap to memoize because I didn't know what to initialize my memo table to.
  That was too slow.
  I used a separate seen array to determine if that node is memoized.
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

const int N = 600;
vector<int> adj[N+1];
int n, m;
ld dp[N+1];
bool seen[N+1];

ld solve(int u, int del){
  if (u == n) return 0;
  if (seen[u]) return dp[u];
  int sz = adj[u].size();
  ld ret = 0;

  ld hi = 0;
  for (int v : adj[u]){
    ld x = solve(v, del);
    ret += x;
    hi = max(hi, x);
  }

  if (u == del && sz > 1) {
    ret -= hi;
    sz--;
  }
  ret /= sz;
  seen[u] = 1;
  return dp[u] = ret+1;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int m; cin >> n >> m;
  for (int i = 0; i < m; i++){
    int s, t; cin >> s >> t;
    adj[s].push_back(t);
  }

  cout << setprecision(10) << fixed;

  ld ans = 1e18;
  for (int i = 1; i <= n; i++){
    memset(seen, 0, sizeof seen);
    ans = min(ans, solve(1,i));
  }
  cout << ans << endl;
  return 0;
}
