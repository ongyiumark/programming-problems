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
  ll n, m; cin >> n >> m;
  vector<int> a(n), b(n);
  for (int i = 0; i < n-1; i++) cin >> a[i];
  a[n-1] = 1;
  for (int i = 0; i < n; i++) cin >> b[i];
  sort(a.rbegin(), a.rend());

  vector<int> amatch(n);
  for (int i = 0; i < n-1; i++) amatch[i] = a[i];

  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());

  int matched = 0;
  int j = 0;
  for (int i = 0; i < n-1; i++) {
    if (b[j] > a[i]) {
      amatch[i] = j;
      j++;
      matched++;
    }
  }
  ll ans = 0;
  int curr = 1;
  for (int i = n-1; i >= 0; i--) {

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
