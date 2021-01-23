/*
  The probablity of getting all correct is 1/2^m.
  So, you're expected to resubmit 2^m times.
*/
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

ll fastpow(ll b, ll e){
  ll ans = 1;
  while(e > 0){
    if (e&1) ans *= b;
    b *= b;
    e >>= 1;
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, m;
  cin >> n >> m;

  cout << (100*(n-m) + 1900*m)*fastpow(2, m) << endl;
  return 0;
}
