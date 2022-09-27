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

const int N = 305;
int a[N];
void testcase(){
  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a+n);
  
  int ans = 1e9;
  for (int i = 1; i < n-1; i++) {
    ans = min(ans, a[i]-a[i-1] + a[i+1]-a[i]);
  }
  cout << ans << "\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while(t--) testcase();
  
  return 0;
}
