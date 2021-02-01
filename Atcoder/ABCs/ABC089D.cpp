/*
  Since we repeatedly advance by d, we can simply do prefix sums across i and i+d.
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
  int h, w, d; cin >> h >> w >> d;
  pii square[h*w+1];
  memset(square, 0, sizeof square);
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      int a; cin >> a;
      square[a] = {i, j};
    }
  }

  int cost[h*w+1];
  memset(cost, 0, sizeof cost);
  for (int i = 1; i <= d; i++){
    for (int j = i; j+d <= h*w; j+=d){
      cost[j+d] = abs(square[j].first-square[j+d].first) + abs(square[j].second-square[j+d].second);
    }
    for (int j = i+d; j <= h*w; j+=d){
      cost[j] += cost[j-d];
    }
  }

  int q; cin >> q;
  while(q--){
    int l, r; cin >> l >> r;
    int ans = cost[r]-cost[l];
    cout << ans << endl;  
  }
  return 0;
}
