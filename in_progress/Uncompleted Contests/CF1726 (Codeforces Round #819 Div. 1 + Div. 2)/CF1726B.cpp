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

int findsmallest(int d) {
  for (int i = 2; i*i <= d; i++) {
    if (d%i == 0) return i;
  }
  return d;
}


void testcase() {
  int n, m; cin >> n >> m;
  int x = m/n;
  int d = m%n;

  if (x == 0) {
    cout << "No" << endl;
    return;
  }

  if (d == 0) {
    cout << "Yes" << endl;
    for (int i = 0; i < n; i++) {
      cout << x;
      if (i < n-1) cout << " ";
      else cout << endl;
    }
    return;
  }

  if (n % 2 == 1) {
    cout << "Yes" << endl;
    cout << x+d;
    for (int i = 0; i < n-1; i++) {
      cout << " " << x;
    }
    cout << endl;
    return;
  }

  if (d%2 == 1) {
    cout << "No" << endl;
    return;
  }

  cout << "Yes" << endl;
  cout << x+d/2 << " " << x+d/2;
  for (int i = 0; i < n-2; i++) {
    cout << " " << x;
  }
  cout << endl;

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while(t--) {
    testcase();
  }
  return 0;
}
