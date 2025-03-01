/*
  Use the lowest costing doughnut to make the rest.
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
  int n,x; cin >> n >> x;
  int lo = 1e9;
  for (int i = 0; i < n; i++){
    int m; cin >> m;
    x -= m;
    lo = min(lo,m);
  }

  cout << n+x/lo << endl;
  return 0;
}
