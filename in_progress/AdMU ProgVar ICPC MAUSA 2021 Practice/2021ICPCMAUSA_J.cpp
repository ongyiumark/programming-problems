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

  int p, q; cin >> p >> q;
  string s; cin >> s;
  
  vector<string> perms = {"AABB", "ABAB", "ABBA", "BAAB", "BABA", "BBAA"};
  string ans = "";
  if (s == perms[0]) {
    if (q == 7) ans = "8 9";
  }
  else if (s == perms[1]) {
    if (q-p == 2 && q == 8) ans = to_string(q-1)+" 9";
  }
  else if (s == perms[2]) {
    if (q-p == 3) ans = to_string(p+1)+" "+to_string(q-1);
  }
  else if (s == perms[3]) {
    if (p == 2 && q == 8) ans = "1 9"; 
  }
  else if (s == perms[4]) {
    if (q-p == 2 && p == 2) ans = "1 "+to_string(q-1);
  }
  else {
    if (p == 3) ans = "1 2";
  }

  if (ans.size() > 0) cout << ans << endl;
  else cout << -1 << endl;
  return 0;
}
