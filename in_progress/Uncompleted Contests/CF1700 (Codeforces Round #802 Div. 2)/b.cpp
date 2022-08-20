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
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    string s; cin >> s;
    if (s[0] != '9') {
      for (char ch : s) {
        cout << 9-(ch-'0');
      }
      cout << endl;
    }
    else {
      vector<int> sint(n+1), tint(n+1);
      for (int i = 0; i < n+1; i++) {
        if (i > 0) sint[i] = s[i-1]-'0';
        tint[i] = 1;
      }
      vector<int> ans(n+1);
    
      for (int i = n; i >= 0; i--) {
        if (tint[i] >= sint[i]) ans[i] = tint[i]-sint[i];
        else {
          ans[i] = tint[i]+10-sint[i];
          tint[i-1]--;
        }
      }
      for (int i = 1; i <= n; i++) {
        cout << ans[i];
      }
      cout << endl;
    }
  }
  
  return 0;
}
