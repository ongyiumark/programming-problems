/*
  Sort and count up.
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

void testcase(){
  int n; cin >> n;
  int s[n];
  for (int i = 0; i < n; i++) cin >> s[i];
  sort(s, s+n);
  int cnt = 1;
  for (int i = 0; i < n; i++) {
    if (cnt > s[i]) continue;
    cnt++;
  }
  cout << cnt-1 << "\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  for (int x = 1; x <= t; x++){
    cout << "Case #" << x << ": ";
    testcase();
  }
  return 0;
}
