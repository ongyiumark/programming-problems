/*
  Use a map to assign points to a certain string.
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
  map<string, int> cost;
  for (int i = 0; i < n; i++){
    string s; cin >> s;
    cost[s]++;
  }
  int m; cin >> m;
  for (int i = 0; i < m; i++){
    string s; cin >> s;
    cost[s]--;
  }

  int ans = 0;
  for (auto it : cost){
    ans = max(ans, it.second);
  }
  cout << ans << endl;
  return 0;
}
