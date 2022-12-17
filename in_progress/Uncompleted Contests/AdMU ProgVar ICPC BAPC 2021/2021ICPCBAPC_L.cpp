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
  vector<ll> rowsums(n, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ll x; cin >> x;
      rowsums[i] += x;
    }
  }
  sort(rowsums.begin(), rowsums.end());
  ll ans = 0;
  for (int i = 0; i < n; i++){
    if (i < n/2) ans += rowsums[i];
    else ans -= rowsums[i];
  }

  cout << abs(ans)/2 << endl;

  return 0;
}
