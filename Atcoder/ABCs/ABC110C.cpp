/*
  We just need to check 2 conditions:
    1. If s[i] == s[j], then t[i] == t[j].
    2. If t[i] == t[j], then s[i] == s[j].
  Maintain two maps.
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

string s, t;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> s >> t;
  int n = s.size();
  map<char, char> st, ts;
  bool valid = 1;
  for (int i = 0; i < n; i++){
    if (st.find(s[i]) != st.end() && st[s[i]] != t[i]){
      valid = 0;
      break;
    }
    if (ts.find(t[i]) != ts.end() && ts[t[i]] != s[i]){
      valid = 0;
      break;
    }
    st[s[i]] = t[i];
    ts[t[i]] = s[i];
  }

  cout << (valid ? "Yes" : "No") << endl;
  return 0;
}
