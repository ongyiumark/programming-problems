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
  int n = s.size();

  int cnt[26];
  memset(cnt, 0, sizeof cnt);

  for (int i = 0; i < n; i++){
    cnt[s[i]-'a']++;
  }

  stack<char> t;
  string ans;

  for (int i = 0; i < n; i++){
    t.push(s[i]);
    cnt[s[i]-'a']--;

    // Move to the answer while its less than or equal to any of the remaining characters.
    while(!t.empty()){
      int x = t.top()-'a';
      bool valid = true;
      for (int j = 0; j < x; j++){
        valid &= cnt[j] == 0;
      }

      if (!valid) break;

      ans += t.top();
      t.pop();
    }
  }
  cout << ans << endl;
  return 0;
}
