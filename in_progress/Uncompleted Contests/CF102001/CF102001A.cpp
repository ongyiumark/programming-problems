/*
  All O's or all 1's, depending on which has more.
  If it's even, then flip the first bit and do it for the rest.
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

string solve(string s){
  int cnt = 0;
  for (char c : s){
    cnt += (c == '1');
  }

  string res = "";
  if (2*cnt > s.size()) res.append(s.size(),'0');
  else res.append(s.size(), '1');
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s; cin >> s;
  
  int n = s.size();
  if (n%2==1) cout << solve(s) << endl;
  else cout << (s[0] == '1' ? "0" : "1")+solve(s.substr(1)) << endl;
  
  return 0;
}
