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

int memo[101][101][2][2];
bool solve(int even, int odd, int player, int res) {
  int &val = memo[even][odd][player][res];
  if (val != -1) return val;
  if (even == 0 && odd == 0) {
    return res == 0;
  }
  val = 0;
  if (player == 1) {
    if (even > 0) val |= solve(even-1, odd, 1-player, res);
    if (odd > 0) val |= solve(even, odd-1, 1-player, 1-res);
  }
  else {
    bool tmp = 1;
    if (even > 0) tmp &= solve(even-1, odd, 1-player, res);
    if (odd > 0) tmp &= solve(even, odd-1, 1-player, res);
    val = tmp;
  }
  return val;
}

void testcase() {
  int n; cin >> n;
  ll a[n];
  int even = 0;
  int odd = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i]%2 == 0) even += 1;
    else odd += 1;
  }
  
  memset(memo, -1, sizeof memo);
  bool isAlice = solve(even, odd, 1, 0);
  cout << (isAlice ? "Alice" : "Bob") << "\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--) testcase();
  return 0;
}
