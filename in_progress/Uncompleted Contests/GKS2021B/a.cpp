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

int n;
string s;

void testcase(){
  cin >> n;
  cin >> s;

  int cnt[26];
  memset(cnt, 0, sizeof cnt);
  int j = 0;
  for (int i = 0; i < n; i++){
    while(true){
      bool found = 0;
      for (int k = s[i]-'A'; k < 26; k++){
        if (cnt[k] > 0) found = 1;
      }
      if (found) {
        cnt[s[j]-'A']--;
        j++;
      }
      else break;
    }
    cout << i-j+1;
    if (i == n-1) cout << "\n";
    else cout << " ";
    cnt[s[i]-'A']++;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  for (int x = 1; x <= t; x++){
    cout << "Case #" << x << ": ";
    testcase();
  }
  return 0;
}
