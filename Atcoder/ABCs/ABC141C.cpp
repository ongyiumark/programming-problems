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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, k, q; cin >> n >> k >> q;
  vector<int> d(n+2);
  for (int i = 0; i < q; i++) {
    int a; cin >> a;
    d[0]--; d[a]++;
    d[a+1]--; d[n+1]++;
  }

  vector<int> a(n+1);
  for (int i = 0; i <= n; i++) a[i] = (i > 0 ? a[i-1] : 0) + d[i];
  for (int i = 1; i <= n; i++) cout << (a[i]+k > 0 ? "Yes" : "No") << "\n";
  return 0;
}
