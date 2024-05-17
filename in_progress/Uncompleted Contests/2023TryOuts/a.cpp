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

  ll n; cin >> n;
  ll total = 0;

  ll ans = 1e18;
  for (int i = 0; i < n; i++) {
    ll t; cin >> t;
    total += t;
    ans = min(ans, total);
  }

  cout << max(0LL, -ans) << "\n";
  
  return 0;
}
