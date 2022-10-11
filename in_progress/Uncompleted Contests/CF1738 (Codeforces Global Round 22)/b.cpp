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

const int N = 1e5+5;
ll a[N], pref[N];
ll n, k;

void testcase() {
  cin >> n >> k;
  for (int i = n-k; i < n; i++) cin >> pref[i];

  bool val = 1;
  for (int i = n-1; i > n-k; i--) {
    a[i] = pref[i]-pref[i-1];
    if (i < n-1 && a[i] > a[i+1]) val = 0; 
  }

  if (k > 1 && pref[n-k] > a[n-k+1]*(n-k+1)) val = 0;
  
  if (val) cout << "Yes\n";
  else cout << "No\n";

}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while(t--) testcase();
  return 0;
}
