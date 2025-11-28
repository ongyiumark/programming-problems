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
  cin.tie(0)->sync_with_stdio(false);
  int n; cin >> n;
  vector<ll> s(1<<n);
  for (ll &x : s) cin >> x;
  sort(s.begin(), s.end(), greater<ll>());

  bool valid = true;
  for (ll i = 1, pow2 = 1; i < (1<<n); i++) {
    if (i == pow2*2) pow2 *= 2;
    if (s[i-pow2] <= s[i]) valid = false;
  }

  cout << (valid ? "Yes" : "No") << "\n";
  return 0;
}
