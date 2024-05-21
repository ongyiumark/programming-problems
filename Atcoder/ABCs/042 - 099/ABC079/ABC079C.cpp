/*
  Try all 8 possibilities. This can be done nicely with bitmask on 8.
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

  string s; cin >> s;

  for (int i = 0; i < 8; i++){
    string ans;
    ans += s[0];
    int total = s[0]-'0';
    for (int j = 0; j < 3; j++){
      if ((1<<j)&i) {
        total += s[j+1]-'0';
        ans += "+";
        ans += s[j+1];
      }
      else {
        total -= s[j+1]-'0';
        ans += "-";
        ans += s[j+1];
      }
    }
    if (total == 7) {
      cout << ans << "=7" << endl;
      return 0;
    }
  }
  return 0;
}
