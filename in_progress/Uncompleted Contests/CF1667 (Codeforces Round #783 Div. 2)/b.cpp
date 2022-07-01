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

const int N = 2e5+5;
ll a[N];

void testcase(){
  int n; ll m; cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  ll total = 0;
  sort(a,a+n);
  for (int i = 1; i < n; i++) total += a[i];
  total += a[n-1] + n;
  if (total <= m) cout << "Yes" << endl;
  else cout << "No" << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while (t--){
    testcase();
  }
  return 0;
}
