/*
  Sort and check consecutive numbers.
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

const int N = 1e5+4;
int h[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k; cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> h[i];
  sort(h, h+n);
  int ans = 1e9;
  for (int i = 0; i < n-k+1; i++){
    ans = min(ans, h[i+k-1]-h[i]);
  }
  cout << ans << endl;
  return 0;
}
