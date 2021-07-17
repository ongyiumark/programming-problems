/*
  Not quite sure the time complexity of this, but it's still brute force, just smarter.
  I noticed that it doesn't actually matter whether or not you decrease the largest.
    Just decrease whatever is larger than n-1.
  
  If you do some math, the maximum value will decrease by a factor of n/(n-1) each time,
    so it ~O(lg_n(MAX)) time.  
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

const int N = 50;
ll a[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  ll ans = 0;

  while(true){
    ll add[n];
    memset(add, 0, sizeof add);
    bool stop = true;
    for (int i = 0; i < n; i++){
      ll d = a[i]/n;
      a[i] %= n;
      ans += d;
      if (d > 0) stop = false;
      if (d == 0) continue;
      if (i > 0) {
        add[0]+=d;
        add[i]-=d;
      }
      if (i + 1 < n) add[i+1]+=d;
    }
    if (stop) break;
    a[0] += add[0];
    for (int i = 1; i < n; i++){
      add[i] += add[i-1];
      a[i] += add[i];
    }
  }

  cout << ans << endl;

  return 0;
}
