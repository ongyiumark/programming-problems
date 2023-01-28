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
  
  ll n; cin >> n;
  if (n&1) {
    cout << 0 << "\n";
    return 0;
  }

  ll fives = 0;
  ll twos = n/2;

  n /= 2;
  ll p = 5;
  while (n/p > 0) {
    fives += n/p;
    p *= 5;
  }

  p = 2;
  while(n/p > 0) {
    twos += n/p;
    p *= 2;
  }

  cout << min(fives, twos) << "\n";

  return 0;
}
