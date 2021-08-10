/*
  Just multiply by 380000 if its BTC.
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
  int n; cin >> n;
  ld total = 0;
  for (int i = 0; i < n; i++){
    ld x; string u;
    cin >> x >> u;
    if (u == "BTC") x*=380000;
    total += x;
  }
  cout << setprecision(10) << fixed << total << endl;
  return 0;
}
