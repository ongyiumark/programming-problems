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

const ll M = 1e9+6969;
const ll N = 2e5+5;
ll u[N];

ll fact[N];
ll revfact[N];
ll cnt[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> u[i+1];
  }

  fact[0] = 1;
  for (int i = 1; i <= n; i++) fact[i] = i*fact[i-1]%M;
  revfact[n] = n;
  for (int i = n-1; i > 0; i--) revfact[i] = i*revfact[i+1]%M;

  cnt[n] = fact[n-1];
  for (int i = n-1; i > 0; i--) {
    cnt[i] = fact[i-1] * revfact[i+1] % M;
    cnt[i] = (cnt[i] + cnt[i+1]) %M;
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += cnt[i]*u[i]%M;
    ans %= M;
  }

  cout << ans << endl;

  return 0;
}
