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
  
  ll a; cin >> a;
  string s, t; cin >> s >> t;
  
  map<string, int> thresh {{"G",0}, {"PG",13}, {"R-13",13}, {"R-16",16}, {"R-18",18}};
  if (a < thresh[s]) {
    if (s == "PG") cout << "OK IF ACCOMPANIED";
    else cout << "ACCESS DENIED";
  }
  else cout << "OK";
  cout << endl;
  return 0;
}
