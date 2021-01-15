/*
  For each 1 by 1 rectangle, count how many times it contributes to the whole sum.
  This is O(nm).
  We can turn it to O(n+m) by rearranging the summation.
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

const ll MOD = 1e9+7;
const int N = 1e5;
ll x[N], y[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++){
    cin >> x[i];
  }
  
  for (int i = 0; i < m; i++){
    cin >> y[i];
  }

  ll mtotal = 0;
  for (int i = 1; i < m; i++){
    ll curr = (y[i]-y[i-1])%MOD;
    curr = curr*i%MOD;
    curr = curr*(m-i)%MOD;
    mtotal = (mtotal + curr)%MOD;
  }
  ll ntotal = 0;
  for (int i = 1; i < n; i++){
    ll curr = (x[i]-x[i-1])%MOD;
    curr = curr*i%MOD;
    curr = curr*(n-i)%MOD;
    ntotal = (ntotal + curr)%MOD;
  }
  cout << ntotal*mtotal%MOD << endl;
  return 0;
}
