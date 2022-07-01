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

void testcase(){
  string s; cin >> s;
  string ans = "";
  int n = s.size();
  string cmp = s;
  for (int i = 0; i < n; i++) {
    bool val = 0;
    string a = "";
    string b = "";
    a.append(1,s[i]);
    a += s.substr(i);
    b = s.substr(i);
    val = (a <= b);


    if (val) ans.append(2,s[i]);
    else ans.append(1,s[i]);
  }
  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  for (int x = 1; x <= t; x++) {
    cout << "Case #" << x << ": ";
    testcase();
  }
  
  return 0;
}
