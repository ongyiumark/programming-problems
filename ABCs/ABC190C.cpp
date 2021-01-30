/*
  Just try all 2^k possibilities of ball placements.
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

const int  N = 100;
int a[N], b[N];
int c[16], d[16];
bool dish[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++){
    cin >> a[i] >> b[i];
  }
  int k; cin >> k;
  for (int i = 0; i < k; i++){
    cin >> c[i] >> d[i];
  }

  int ans = 0;
  for (int x = 0; x < (1<<k); x++){
    memset(dish, 0, sizeof dish);
    for (int i = 0; i < k; i++){
      if(x&(1<<i)) dish[c[i]] = 1;
      else dish[d[i]] = 1;
    }
    int cnt = 0;
    for (int i = 0; i < m; i++){
      cnt += dish[a[i]]&dish[b[i]];
    }
    ans = max(cnt, ans);
  }
  cout << ans << endl;
  return 0;
}
