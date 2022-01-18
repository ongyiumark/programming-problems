/*
  |E|/2 boomerangs is always possible where E is the edges in each connected component.
  We can solve this for a tree by starting from the leaves going up.

  Then, we can turn a general graph into a tree by add new nodes when cycles occur.
    Just remember to map the new nodes to their original id.
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

const int N = 3e5;
vector<int> graph[N];
map<int,int> newnodes;
vector<tuple<int,int,int>> ans;
map<pair<int,int>, bool> visedges;
bool vis[N];
int par[N];
int n;

int solve(int u){
  vis[u] = 1;
  //cout << u+1 << endl;
  vector<int> freechildren;
  for (int v : graph[u]){
    if (visedges[{min(u,v), max(u,v)}]) continue;
    visedges[{min(u,v), max(u,v)}] = true;
    if (vis[v]) {
      newnodes[n] = v;
      par[n] = u;
      freechildren.push_back(n);
      n++;
      continue;
    }

    par[v] = u;
    int tmp = solve(v);
    if (tmp != -1) freechildren.push_back(tmp);
  }

  int m = freechildren.size();
  for (int i = m%2; i < m; i+=2){
    ans.push_back({freechildren[i], u, freechildren[i+1]});
  }

  if (m%2 == 1){
    if (par[u] != -1) ans.push_back({freechildren[0], u, par[u]});
    return -1;
  }
  else return u;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int m; cin >> n >> m;
  int ogn = n;
  for (int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    u--; v--;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  memset(vis, 0, sizeof vis);
  for (int i = 0; i < n; i++){
    if (vis[i]) continue;
    par[i] = -1;
    solve(i);
  }  

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++){
    int tmp1 = get<0>(ans[i]);
    int tmp2 = get<1>(ans[i]);
    int tmp3 = get<2>(ans[i]);
    if (tmp1 >= ogn) tmp1 = newnodes[tmp1];
    if (tmp2 >= ogn) tmp2 = newnodes[tmp2];
    if (tmp3 >= ogn) tmp3 = newnodes[tmp3];
    
    cout << tmp1+1 << " " << tmp2+1 << " " << tmp3+1 << endl;
  }
  return 0;
}
