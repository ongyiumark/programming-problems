/*
  Process it backwards.
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

  string s; cin >> s;
  vector<string> patterns = {"dreamer", "dream", "eraser", "erase"};

  int i = s.size();
  while(i > 0){
    bool found = false;
    for (string pattern : patterns){
      int m = pattern.size();
      if (i-m < 0) continue;
      if (s.substr(i-m, m) == pattern) {
        i -= m;
        found = true;
        break;
      } 
    }

    if (!found) {
      cout << "NO" << endl;
      return 0;
    } 
  }
  cout << "YES" << endl;
  return 0;
}
