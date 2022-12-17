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
    int n; cin >> n;
    string s; cin >> s;
    string res = "";
    int par = s[0]-'0';
    for (int i = 1; i < n; i++) {
      par += s[i]-'0';
      if (s[i] == '0') res += "+";
      else if (par&1) res += "+";
      else res += "-"; 
    }

    cout << res << "\n";
  }  
  
  return 0;
}
