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
  vector<int> a(n), b(n);
  a[0] = m;
  for (int i = 1; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];

  sort(a.rbegin(), a.rend());
  priority_queue<int> pq;
  for (int i = 0; i < n; i++) pq.push(b[i]);

  int matched = 0;
  for (int i = 0; i < n; i++) {
    if (pq.empty()) continue;
    if (pq.top() > a[i]) {
      pq.pop();
      matched++;
    }
  }
  cout << n-matched << "\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while(t--) testcase();

  return 0;
}
