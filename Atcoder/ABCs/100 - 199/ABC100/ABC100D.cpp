/*
  Lets consider the contribution of the i-th cake to the total score.
  It can contribute in 8 ways: +-x[i] +-y[i] +-z[i].

  Let's try all 8 possibilities.
  But the contribution of all cakes must be the same +-.
  For example if the contribution of the i-th cake is x[i]-y[i]+z[i], 
    the contribution of the j-th cake is also x[j]-y[j]+z[j].
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
const int N = 1000+5;

ll x[N], y[N], z[N];

vector<ll> arr[8];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++){
    cin >> x[i] >> y[i] >> z[i];
    for (int j = 0; j < 8; j++){
      ll tx = x[i]*((1<<0)&j ? 1 : -1);
      ll ty = y[i]*((1<<1)&j ? 1 : -1);
      ll tz = z[i]*((1<<2)&j ? 1 : -1);
      arr[j].push_back(tx+ty+tz);
    }
  }

  ll ans = 0;
  for(int i = 0; i < 8; i++){
    sort(arr[i].begin(), arr[i].end(), greater<ll>());
    ll cans = 0;
    for (int j = 0; j < m; j++){
      cans += arr[i][j];
    }
    ans = max(ans, cans);
  }

  cout << ans << endl;
  return 0;
}
