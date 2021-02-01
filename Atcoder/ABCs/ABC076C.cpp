/*
  Constraints are small enough to brute force all possiblities and sort.
  If there are any leftover '?'s, it's always optimal to turn that into 'a'.
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
  string s, t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();

  vector<string> ans;
  for (int i = 0; i < n-m+1; i++){
    bool valid = 1;
    for (int j = 0; j < m; j++){
      if (s[i+j] == '?') continue; 
      if (s[i+j] != t[j]) valid = 0;
    }
    if (valid){
      string temp = s.substr(0,i)+t;
      if (i+m < n) temp += s.substr(i+m);
      for (char &c : temp){
        if (c == '?') c = 'a'; 
      }
      ans.push_back(temp);
    }
  }

  sort(ans.begin(), ans.end());
  if (ans.size() == 0) cout << "UNRESTORABLE" << endl;
  else cout << ans[0] << endl;
  return 0;
}
