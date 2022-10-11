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

const int N = 1e5+5;
const ll INF = 1e18;
ll X[N],Y[N];

ll solve(ll x, ll y, int n) {
  ll d = 0;
  ll hi = 0;
  for (int i = 0; i < n; i++) {
    ll tmp = abs(x-X[i])+abs(y-Y[i]);
    d += tmp*2;
    hi = max(hi,tmp);
  }
  return d-hi;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll w, h; cin >> w >> h;
  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> X[i] >> Y[i];

  ll best = INF;
  pair<int,int> ans = {w,h};
  for (ll x = 1; x <= w; x++) {
    for (ll y = 1; y <= h; y++) {
      ll tmp = solve(x,y,n);
      //cout << i << " " << j << " " << tmp << endl;
      if (best >= tmp) {
        if (best == tmp) {
          if (ans > pii({x,y})) {
            ans = pii({x,y});
          }
        }
        else ans = pii({x,y});
        best = min(best,tmp);
      }
    }
  }

  cout << best << endl;
  cout << ans.first << " " << ans.second << endl;
  
  return 0;
}
