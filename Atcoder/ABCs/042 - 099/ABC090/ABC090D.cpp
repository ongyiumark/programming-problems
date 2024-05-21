/*
  Fix b. Suppose b > k.
  Notice that in the sequence: 0%b, 1%b, 2%b, ..., N%b
  0, 1, 2, ..., b-1 repeats floor(n/b) times.
  Then, it is followed by 0, 1, 2, ..., n%b.

  We can do some math to count how many of these are greater than or equal to k.
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
  
  int n, k; cin >> n >> k;
  ll ans = 0;
  for (int b = k+1; b <= n; b++){
    ans += (b-k)*(n/b) + max(0, n%b-k+1);
  }
  if (k == 0) ans -= n;
  cout << ans << endl;
}
