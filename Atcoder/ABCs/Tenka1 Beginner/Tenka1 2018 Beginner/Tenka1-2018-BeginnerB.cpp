/*
  Just simulate.
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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll a, b, k;
  cin >> a >> b >> k;
  for (int i = 0; i < k; i++){
    if (i%2 == 0) a/=2, b+=a;
    else b/=2, a+=b;
  }

  cout << a << " " << b << endl;
  return 0;
}
