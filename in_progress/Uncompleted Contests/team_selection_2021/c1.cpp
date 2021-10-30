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
ll a[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  ll total = 0;
  for (int i = 1; i <= n; i++){
    cin >> a[i];
    total += a[i];
  }

  ll best = -1e18;
  //if (n > 16) return 0;
  for (int mask = 0; mask < (1<<n); mask++){
    ll score = total;
    bool vis[n+5];
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < n; i++){
      if (mask&(1<<i)) {
        int mult = i+1;
        for (int j = mult; j <= n; j+=mult){
          if (vis[j]) continue;
          vis[j] = 1;
          score -= a[j];
        }
      }
    }
    best = max(score, best);
  }

  cout << best << endl;

  return 0;
}
