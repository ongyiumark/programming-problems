/*
  Just add the weights.
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

string s;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--){
    ll w; cin >> w;
    cin >> s;
    for (char c : s){
      w -= (c-'A'+1);
      if (w < 0) break;
    }
    cout << (w >= 0 ? "YES" : "NO") << endl;
  }
  return 0;
}
