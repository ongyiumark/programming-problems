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
ll prefix[N];

void testcase(){
  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a+n);

  ll hi = a[0];
  prefix[0] = a[0];
  for (int i = 1; i < n; i++){
    hi = max(a[i]-prefix[i-1], hi);
    a[i] -= prefix[i-1];
    prefix[i] = prefix[i-1]+a[i];
  }
  cout << hi << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  for (int k = 0; k < t; k++){
    testcase();
  }
  return 0;
}
