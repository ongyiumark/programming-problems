/*
  Multiply by 1000 to bypass floating points.
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
  
  int n; cin >> n;
  int t,a; cin >> t >> a;
  int ans = 0;
  ll score = 1e9;
  for (int i = 0; i < n; i++){
    int x; cin >> x;
    ll tmp = abs(1000*a-(1000*t-x*6));
    if (score > tmp){
      score = tmp;
      ans = i+1;
    }
  }


  cout << ans << endl;
  return 0;
}
