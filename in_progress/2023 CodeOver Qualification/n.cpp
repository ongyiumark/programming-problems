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

  int n, m; cin >> n >> m;
  ll total = 0;
  unordered_map<int,int> last_seen;

  for (int i = 1; i <= m; i++) {
    int x; cin >> x;
    total += (n-1)-(i-last_seen[x]-1);
    last_seen[x] = i;
    cout << total << "\n";
  }

  
  return 0;
}
