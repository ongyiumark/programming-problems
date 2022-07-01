/*
  Count the number of increasing. Restart the count every time it doesn't increase.
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

const int N = 1e5+5;
int a[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int ans = 1;
  int cnt = 1;
  for (int i = 1; i < n; i++) {
    if (a[i-1] < a[i]) cnt++;
    else {
      ans = max(cnt, ans);
      cnt = 1;
    }
  }
  ans = max(ans, cnt);
  cout << ans << endl;
  return 0;
}
