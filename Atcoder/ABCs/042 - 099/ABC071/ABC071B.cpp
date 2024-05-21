/*
  Boolean for each letter.
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

  bool mex[26];
  string s; cin >> s;
  memset(mex, 0, sizeof mex);
  for (char c : s){
    mex[c-'a'] = 1;
  }

  int i;
  for (i = 0; i < 26; i++){
    if (!mex[i]) break;
  }
  if (i == 26) cout << "None" << endl;
  else cout << (char)(i+'a') << endl;
  return 0;
}
