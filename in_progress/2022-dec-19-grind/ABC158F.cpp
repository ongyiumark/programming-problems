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

const ll MOD = 998244353;
const int N = 2e5+5;

ll x[N], d[N];
pair<ll, ll> nodes[N];
int par[N], far[N];
int n;

vector<int> graph[N];
bool vis[N];

ll dfs(int u) {
  vis[u] = 1;
  
  ll ans = 1;
  for (int v : graph[u]) {
    if (vis[v]) continue;
    ans = ans * dfs(v)%MOD;
  }
  ans = (ans + 1) % MOD;
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> d[i];
    nodes[i] = {x[i], d[i]};
  }
  sort(nodes, nodes+n);

  // compute farthest reach
  for (int i = 0; i < n; i++) far[i] = i;

  for (int i = 0; i < n; i++) {
    int lo = i+1;
    int hi = n-1;

    while(lo <= hi) {
      int mid = hi - (hi-lo)/2;
      if (nodes[mid].first < nodes[i].first + nodes[i].second) {
        far[i] = mid;
        lo = mid+1;
      }
      else hi = mid-1;
    }
  }

  // compute parents
  for (int i = 0; i < n; i++) par[i] = -1;
  stack<int> st;
  for (int i = n-1; i >= 0; i--) {
    while(!st.empty() && st.top() <= far[i]) {
      par[st.top()] = i;
      st.pop();
    }
    st.push(i);
  } 

  // build graph
  for (int i = 0; i < n; i++) {
    if (par[i] == -1) continue;
    graph[par[i]].push_back(i);
  }
  
  // compute ans
  ll ans = 1;
  for (int i = 0; i < n; i++) vis[i] = 0;
  for (int i = 0; i < n; i++) {
    if (vis[i]) continue;
    ll curr = dfs(i);
    ans = ans*curr%MOD;
  }
  cout << ans << "\n";
  return 0;
}
