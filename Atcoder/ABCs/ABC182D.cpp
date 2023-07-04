#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;

  vector<ll> a(n), p(n+1), hi(n+1);
  for (ll &x : a) cin >> x;
  for (int i = 0; i < n; i++) p[i+1] = p[i]+a[i];
  for (int i = 0; i < n; i++) hi[i+1] = max(hi[i], p[i+1]);

  ll ans = 0;
  ll curr = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, curr+hi[i]);
    curr += p[i]; 
  }
  cout << ans << "\n";


  return 0;
}
