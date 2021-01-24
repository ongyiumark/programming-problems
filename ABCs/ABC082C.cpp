/*
  Use a map to count the number of times an integer occurs.
  Remove all if the count is less than the integer.
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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  map<int,int> cnt;
  int n; cin >> n;
  for (int i = 0; i < n; i++){
    int a; cin >> a;
    cnt[a]++;
  }
  ll ans = 0;
  for (auto it = cnt.begin(); it != cnt.end(); it++){
    if (it->second < it->first) ans += it->second;
    else ans += it->second - it->first;
  }
  cout << ans << endl;
  return 0;
}
