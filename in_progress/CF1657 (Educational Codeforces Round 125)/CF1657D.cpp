/*
  Precalculate the most damage you can deal for each cost.
  Binary search the answer.
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

const int N = 3e5+5;
ll c[N], d[N], h[N];
ll D[N], H[N];
const int cMAX = 1e6+5;
ll bestC[cMAX];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  memset(bestC, 0, sizeof bestC);
  int n, C; cin >> n >> C;
  for (int i = 0; i < n; i++){
    cin >> c[i] >> d[i] >> h[i];
    bestC[c[i]] = max(bestC[c[i]], d[i]*h[i]);
  }
  int m; cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> D[i] >> H[i];
  }
  for (int i = 1; i <= C; i++){
    for (int j = 1; i*j <= C; j++){
      bestC[i*j] = max(bestC[i*j], bestC[i]*j);
    }
  }
  ll hi = 0;
  for (int i = 0; i <= C; i++) {
    hi = max(hi, bestC[i]);
    bestC[i] = hi;
  }
  for (int i = 0; i < m; i++) {
    ll monster = H[i]*D[i];
    int lo = 0;
    int hi = C;
    int ans = -1;
    while (lo <= hi){
      int mid = hi - (hi-lo)/2;
      if (bestC[mid] > monster){
        ans = mid;
        hi = mid-1;
      }
      else lo = mid+1;
    }
    cout << ans;
    if (i == m-1) cout << endl;
    else cout << " ";
  }

  
  return 0;
}
