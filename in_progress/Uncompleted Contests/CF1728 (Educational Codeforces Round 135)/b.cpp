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

void testcase() {
  int n; cin >> n;
  vector<int> p(n);
  if (n%2 == 0) {
    for (int i = 0; i < n-2; i++) {
      p[i] = n-2-i;
    }
    p[n-2] = n-1;
    p[n-1] = n;
  }
  else {
    p[0] = n-1;
    for (int i = 1; i < n-2; i++) {
      p[i] = n-2-i;
    }
    p[n-2] = n-2;
    p[n-1] = n;
  }


  for (int i = 0; i < n; i++) {
    cout << p[i];
    if (i < n-1) cout << " ";
    else cout << endl;
  }
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
