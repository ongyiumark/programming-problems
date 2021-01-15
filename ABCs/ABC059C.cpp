/*
  Add normally and compensate when it doesn't follow the constraint.
  Try starting with positive and try starting with negative.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5;
ll a[N];

int n;
int sign(ll x){
  if (x < 0) return -1;
  if (x > 0) return 1;
  return 0;
}

ll solve(int val){
  ll ans = 0;
  ll total = 0;
  for (int i = 0; i < n; i++){
    total += a[i];
    if (sign(total) != val){
      ans += abs(total)+1;
      total = val;
    }
    val *= -1;
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  cout << min(solve(1), solve(-1)) << endl;
  return 0;
}
