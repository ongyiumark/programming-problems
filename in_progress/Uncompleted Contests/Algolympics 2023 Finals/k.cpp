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
  int n, m; cin >> n >> m;
  vector<int> k(n), t(m);
  for (int i = 0; i < n; i++) cin >> k[i];

  unordered_set<int> tt;
  for (int i = 0; i < m; i++) {
    cin >> t[i];
    t[i]--;
    tt.insert(t[i]);
  }

  ll total = 0;
  for (int i = 0; i < n; i++) {
    if (tt.find(i) != tt.end()) total += 1;
    else total += 2*k[i];
  }
  
  cout << total + 1 << "\n";
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
