/*
  It's optimal to insert '(' at the very beginning and ')' at the very end.
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
  int n; cin >> n;
  string s; cin >> s;
  int cnt = 0;
  int left = 0;
  for (char c : s){
    if (c == '(') cnt++;
    else cnt--;
    if (cnt < 0) {
      left++;
      cnt = 0;
    }
  }
  
  string ans;
  ans.append(left, '(');
  ans += s;
  ans.append(cnt, ')');
  cout << ans << endl;
  return 0;
}
