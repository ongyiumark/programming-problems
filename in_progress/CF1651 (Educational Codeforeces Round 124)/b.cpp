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
  
  ll x = 1;
  vector<ll> ans;
  while (x <= 1000000000){
    ans.push_back(x);
    x *= 3;
  }

  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    if (n > ans.size()) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      cout << ans[i];
      if (i == n-1) cout << endl;
      else cout << " ";
    }
  }
  return 0;
}
