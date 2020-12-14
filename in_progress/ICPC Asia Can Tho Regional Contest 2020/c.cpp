// unsolved
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

bool isleft(ll a, ll b, ll c, ll d){
  return a*d-b*c >= 0;
}

void testcase(){
  ll a, b, c1, c2;
  cin >> a >> b >> c1 >> c2;
  ll k; cin >> k;

  ll x[k], y[k];
  for (int i = 0; i < k; i++){
    cin >> x[i] >> y[i];
  }

  bool scr1 = isleft(b,-a, b*x[0], b*y[0]-c1);
  bool scr2 = isleft(b,-a, b*x[0], b*y[0]-c2);
  for (int i = 0; i < k; i++){
    bool cr1 = isleft(b,-a, b*x[i], b*y[i]-c1);
    bool cr2 = isleft(b,-a, b*x[i], b*y[i]-c2);
    if (cr1 != cr2 || scr1 != cr1 || scr2 != cr2){
      cout << "YES" << endl;
      return;
    }
  }

  cout << "NO" << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--){
    testcase();
  }
  return 0;
}
