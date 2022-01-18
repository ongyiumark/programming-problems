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

ll solve(ll st, ll n){
  if (st > n) return 0;
  ll terms = (n-st)/4+1;
  ll total = (st+(terms-1)*2)*terms;
  return total;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  for (int k = 0; k < t; k++){
    ll x, n; cin >> x >> n;
    //  1 2 3 4 5 6
    // E O O E E O O...
    if (n == 0){
      cout << x << endl;
      continue;
    }

    ll ans = 0;
    if (x%2 == 0){
      ans = x+solve(2,n)+solve(3,n)-solve(4,n)-solve(5,n)-1;
    }
    else {
      ans = x-solve(2,n)-solve(3,n)+solve(4,n)+solve(5,n)+1;
    }
    cout << ans << endl;
  }
  return 0;
}
