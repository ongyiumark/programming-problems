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

  string s; cin >> s;
  int n = s.size();
  int ans = n;
  for (int mask = 1; mask < (1<<n); mask++) {
    int deleted = n - __builtin_popcount(mask);
    string t = "";
    for (int i = 0; i < n; i++) {
      if (mask&(1<<i)) t += s[i];
    }
    ll t_int = stoll(t);
    if (t_int % 3 == 0) ans = min(ans, deleted);
  }

  cout << (ans == n ? -1 : ans) << "\n";
  
  return 0;
}
