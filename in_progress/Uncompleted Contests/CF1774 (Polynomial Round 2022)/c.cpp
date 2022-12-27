#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while(t--) {
    int num1, num0;
    num0 = num1 = 0;
    int n; cin >> n;
    string s; cin >> s;
    vi ans;
    char prev = '0';
    for (int i = 0; i < n-1; i++) {
      char ch = s[i];
      num0 += (ch == '0');
      num1 += (ch == '1');
      if (i == 0) ans.push_back(1);
      else if (ch == prev) ans.push_back(ans.back());
      else ans.push_back(i+1);
      
      prev = ch;
    }

    cout << ans[0];
    for (int i = 1; i < n-1; i++) {
      cout << " " << ans[i]; 
    }
    cout << "\n";
  }
  
  return 0;
}
