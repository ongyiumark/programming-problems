/*
  You can think of it as a classic nim game with 4 stacks of stones.
  The number of stones is the number of cells to the left, right, above, and below the topping.
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
  int t; cin >> t;
  while(t--){
    int m, n, r, c;
    cin >> m >> n >> r >> c;
    int ans = (r^c^(m-r-1)^(n-c-1));
    cout << (ans == 0 ? "Hansel" : "Gretel") << endl;
  }
  
  return 0;
}