/*
  Binary search K.
  Then to verify if K is valid, push all (a,b) such that d_a+d_b >= k into a queue.
  For each (a,b) in the queue, update the new degree, then push all new valid (a,c) and (b,c).
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

const int N = 505;
bool linked[N][N];
int deg[N];
int n;
int need;

vector<int> not_linked[N];

bool go(int k){
  queue<pii> q;
  bool track[n+1][n+1];
  int tmp_deg[n+1];
  int cnt = 0;
  memset(track, 0, sizeof track);
  for (int i = 1; i <= n; i++) tmp_deg[i] = deg[i];
  for (int i = 1; i <= n; i++){
    for (int j : not_linked[i]) {
      int x = min(i,j);
      int y = max(i,j);
      if (!track[x][y]){
        if (tmp_deg[x]+tmp_deg[y] >= k){
          q.push({x,y});
          track[x][y] = 1;
          cnt++;
        }
      }
    }
  }

  while(!q.empty()){
    pii p = q.front();
    q.pop();
    int a = p.first;
    int b = p.second;
    tmp_deg[a]++;
    tmp_deg[b]++;

    for (int v : not_linked[a]){
      int x = min(a,v);
      int y = max(a,v);
      if (tmp_deg[x] + tmp_deg[y] >= k) {
        if (!track[x][y]){
          q.push({x,y});
          track[x][y] = 1;
          cnt++;
        }
      }
    }

    for (int v : not_linked[b]){
      int x = min(b,v);
      int y = max(b,v);
      if (tmp_deg[x] + tmp_deg[y] >= k) {
        if (!track[x][y]){
          q.push({x,y});
          track[x][y] = 1;
          cnt++;
        }
      }
    }
    if (cnt == need) return true;
  }
 
  return cnt == need;
}



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(deg, 0, sizeof deg);
  memset(linked, 0, sizeof linked);

  int m; cin >> n >> m;
  need = n*(n-1)/2-m;
  for (int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    deg[a]++; deg[b]++;
    linked[a][b] = linked[b][a] = 1;
  }

  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
      if (i == j) continue;
      if (!linked[i][j]) not_linked[i].push_back(j);
    }
  }

  
  int ans = -1;
  int lo = 0;
  int hi = 2*n;
  while(lo <= hi){
    int mid = hi - (hi-lo)/2;
    if (go(mid)){
      ans = mid;
      lo = mid+1;
    }
    else hi = mid-1;
  }
  cout << ans << endl;
  
  return 0;
}
