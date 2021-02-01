/*
  Simply count the frequencies for all strings and get the minimum of all.
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
  int counts[26];
  memset(counts, 127, sizeof counts);
  for (int i = 0; i < n; i++){
    int curr[26];
    memset(curr, 0, sizeof curr);
    string s; cin >> s;
    for (char c : s){
      curr[c-'a']++;
    }
    for (int j = 0; j < 26; j++){
      counts[j] = min(curr[j], counts[j]);
    }
  }

  string ans;
  for (int i = 0; i < 26; i++){
    ans.append(counts[i], i+'a');
  }
  cout << ans << endl;
  return 0;
}
