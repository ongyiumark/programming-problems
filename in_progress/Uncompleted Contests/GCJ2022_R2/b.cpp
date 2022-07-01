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


void testcase() {
  ll r; cin >> r;
  if (r > 100) {
    cout << 1 << endl;
    return;
  }
  int N = 2*r+5;
  bool correct[N][N], wrong[N][N];
  memset(correct, 0, sizeof correct);
  memset(wrong, 0, sizeof wrong);
  for (ll x = -r; x <= r; x++){
    for (ll y = -r; y <= r; y++) {
      if((ll)(sqrtl(x*x+y*y)+0.5) <= r){
        correct[x+r][y+r] = 1;
      }
    }
  }

  for (ll k = 0; k <= r; k++) {
    for (ll x = -k; x <= k; x++) {
      ll y = (ll)(sqrtl(k*k-x*x) + 0.5);
      wrong[x+r][y+r] = 1;
      wrong[x+r][-y+r] = 1;
      wrong[y+r][x+r] = 1;
      wrong[-y+r][x+r] = 1;
    }
  }

  int cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cnt += (wrong[i][j] != correct[i][j]);
    }
  }
  cout << cnt << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  for (int x = 1; x <= t; x++) {
    cout << "Case #" << x << ": ";
    testcase();
  }
  
  return 0;
}
