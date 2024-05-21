/*
  Filter out the overtimes and get the minimum
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

const int N = 1005;
int c[N], d[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, t; cin >> n >> t;
  for (int i = 0; i < n; i++) cin >> c[i] >> d[i];

  int hi = 1e9;
  for (int i = 0; i < n; i++){
    if (d[i] <= t) hi = min(hi, c[i]);
  }
  
  if (hi == 1e9) cout << "TLE" << endl;
  else cout << hi << endl; 
  return 0;
}
