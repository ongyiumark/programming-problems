/*
  BFS from both sources at the same time.
  The players takes turns with 1 layer each.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5+1;
vector<int> adj[N];
int vis[N];

int solve(int n){
  memset(vis, 0, sizeof vis);
  queue<int> qf, qs;
  qf.push(1); qs.push(n);
  pair<int,int> currlayer = {1,1};
  pair<int,int> nextlayer = {0,0};
  pair<int,int> cnt;
  vis[1] = vis[n] = 1;
  while(!qf.empty() || !qs.empty()){
    while (!qf.empty()){
      int u = qf.front();
      qf.pop();
      cnt.first++;
      for (int v : adj[u]){
        if (vis[v]) continue;
        vis[v] = 1;
        nextlayer.first++;
        qf.push(v);
      }
      currlayer.first--;
      if (!currlayer.first){
        currlayer.first = nextlayer.first;
        nextlayer.first = 0;
        break;
      }
    }
    while (!qs.empty()){
      int u = qs.front();
      qs.pop();
      cnt.second++;
      for (int v : adj[u]){
        if (vis[v]) continue;
        vis[v] = 1;
        nextlayer.second++;
        qs.push(v);
      }
      currlayer.second--;
      if (!currlayer.second){
        currlayer.second = nextlayer.second;
        nextlayer.second = 0;
        break;
      }
    }
  }
  return cnt.first > cnt.second;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  for (int i = 0; i < n; i++){
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  cout << (solve(n) ? "Fennec" : "Snuke") << endl;
  return 0;
}
