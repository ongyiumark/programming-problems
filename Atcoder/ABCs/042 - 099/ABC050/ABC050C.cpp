/*
  The answer is 2^(n//2).
  Simply check if the array is valid.
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

ll modpow(ll b, ll e){
  ll ans = 1;
  while(e > 0){
    if (e&1) ans = (ans*b)%MOD;
    b = (b*b)%MOD;
    e >>= 1;
  }
  return ans;
}

unordered_map<int,int> counts;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  bool valid = true;
  for (int i = 0; i < n; i++){
    int a; cin >> a;
    counts[a]++;
    if ((n+a)%2 == 0) valid = false;
    if (counts[a] > 2) valid = false;
  }

  if (n&1){
    if (counts[0] != 1) valid = false;
    for (int i = 2; i <= n-1; i+=2)
      if (counts[i] != 2) valid = false;
  }
  else{
    for (int i = 1; i <= n-1; i+=2)
      if (counts[i] != 2) valid = false;
  }

  if (valid) cout << modpow(2, n/2) << endl;
  else cout << 0 << endl;
  return 0;
}
