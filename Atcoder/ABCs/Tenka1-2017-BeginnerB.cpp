/*
  You only really need to care about the lowest placer.
  Count how many more places you can add after it.
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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  int hi = 0;
  int ans = 0;
  for (int i = 0; i < n; i++){
    int a, b; cin >> a >> b;
    if (hi < a){
      hi = a;
      ans = a+b;
    }
  }
  cout << ans << endl;

  return 0;
}
