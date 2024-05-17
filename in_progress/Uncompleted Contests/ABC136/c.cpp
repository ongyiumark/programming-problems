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

  int n; cin >> n;
  vector<ll> h(n);
  for (ll &x : h) cin >> x;

  ll valid = true;
  for (int i = n-2; i >= 0; i--) {
    if (h[i] <= h[i+1]) continue;
    else if (h[i]-h[i+1] > 1) {
      valid = false;
      continue;
    }

    h[i]--;
  }

  cout << (valid ? "Yes" : "No") << "\n";
  
  return 0;
}
