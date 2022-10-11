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

void testcase() {
  int n; cin >> n;
  int d[n];
  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }

  int a[n];
  a[0] = d[0];
  bool val = 1;
  for (int i = 1; i < n; i++) {
    if (d[i] != 0 && a[i-1]-d[i] >= 0) val = 0;
    a[i] = a[i-1]+d[i]; 
  }
  if (val) {
    for (int i = 0; i < n; i++) {
      cout << a[i];
      if (i < n-1) cout << " ";
      else cout << "\n";
    }
  }
  else {
    cout << -1 << "\n";
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while(t--) testcase();
  
  return 0;
}
