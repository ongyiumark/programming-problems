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

const int N = 2e5+5;
vector<int> p(N);
vector<ld> e(N), pref_e(N);

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k; cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    e[i] = (ld)(p[i]+1)/2;
  }

  ld ans = 0;
  pref_e[0] = e[0];
  for (int i = 1; i < n; i++) {
    pref_e[i] = e[i] + pref_e[i-1];
  }

  for (int r = k-1; r < n; r++) {
    ld curr = pref_e[r];
    if (r-(k-1) > 0) curr -= pref_e[r-(k-1)-1];
    ans = max(ans, curr);
  }

  cout << fixed << setprecision(11) << ans << "\n";

  return 0;
}
