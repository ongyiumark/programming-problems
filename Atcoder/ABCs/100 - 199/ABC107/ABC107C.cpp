/*
  You can separate the positive number from the negative numbers.
  Try taking i positive numbers where i <= k. Then, you would have to go back to 0 and take k-i negative numbers.
  A similar process is done for negative numbers.
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

vector<ll> pos, neg;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k; cin >> n >> k; 
  int lo, hi;
  lo = hi = 0;
  for (int i = 0; i < n; i++){
    int x; cin >> x;
    if (x >= 0) pos.push_back(x);
    else neg.push_back(-x);
  }

  sort(pos.begin(), pos.end());
  sort(neg.begin(), neg.end());
  ll ans = 1e18;
  for (int i = 0; i < (int)pos.size() && i < k; i++){
    ll curr = 2*pos[i];
    if (i == k-1) ans = min(ans, curr/2);
    if (k-i-2 < 0 || k-i-2 >= (int)neg.size()) continue;
    ans = min(curr + neg[k-i-2], ans);
  }
  for (int i = 0; i < (int)neg.size() && i < k; i++){
    ll curr = 2*neg[i];
    if (i == k-1) ans = min(ans, curr/2);
    if (k-i-2 < 0 || k-i-2 >= (int)pos.size()) continue;
    ans = min(curr + pos[k-i-2], ans);
  }
  cout << ans << endl;
  return 0;
}
