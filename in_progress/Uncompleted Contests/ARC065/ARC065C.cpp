/*
  Start from the end.
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

  vector<string> patterns = {"erase", "dream", "eraser", "dreamer"};
  string s; cin >> s;

  int n = s.size();
  int i = n-1;
  while (i >= 0) {
    bool found = 0;
    for (string p : patterns) {
      int m = p.size();
      if (i - m + 1 < 0) continue;
      bool val = 1;
      for (int j = 0; j < m; j++) {
        val &= (p[m-j-1] == s[i-j]);
      }
      if (val) {
        i -= m;
        found = 1;
        break;
      }
    }
    if (!found) break;
  }
  cout << (i==-1 ? "YES" : "NO") << endl;
  return 0;
}
