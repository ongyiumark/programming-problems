/* 
  Sort in non-increasing order. Find the first two largest pairs.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5;
ll a[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  sort(a, a+n, greater<ll>());

  ll ans = 1;
  int cnt = 0;
  for (int i = 1; i < n; i++){
    if (a[i] == a[i-1]){
      ans *= a[i];
      i++;
      cnt++;
      if (cnt == 2) break;
    }
  }
  cout << (cnt == 2 ? ans : 0) << endl;
  return 0;
}
