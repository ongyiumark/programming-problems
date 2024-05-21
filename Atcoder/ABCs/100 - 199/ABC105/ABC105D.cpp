/*
  Make a prefix sum array. 
  If two values are congruent mod m, then that interval satisfies the condition.
  If your prefix array starts at 0, then don't forget to include those that dont have a left endpoint.
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

const int N = 1e5;
ll a[N], pref[N];
map<int, int> mods;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll n, m; cin >> n >> m;
  for (int i = 0; i < n; i++){
    cin >> a[i];
    pref[i] = a[i];
    if (i > 0) pref[i] += pref[i-1];
    pref[i] %= m;
  }

  ll cnt = 0;
  for (int i = 0; i < n; i++){
    cnt += mods[pref[i]];
    mods[pref[i]]++;
  }
  cout << cnt+mods[0] << endl;
  return 0;
}
