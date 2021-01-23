/*
  Use Floyd-Warshall to get all sources shortest path.
  You can also do dijkstra from all sources but that accomplishes the same thing.
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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int h, w; cin >> h >> w;
  int cost[10][10];
  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
      cin >> cost[i][j];
    }
  }

  for (int k = 0; k < 10; k++){
    for (int i = 0; i < 10; i++){
      for (int j = 0; j < 10; j++){
        cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      int x; cin >> x;
      if (x == -1) continue;
      ans += cost[x][1];
    }
  }
  cout << ans << endl;
  return 0;
}
