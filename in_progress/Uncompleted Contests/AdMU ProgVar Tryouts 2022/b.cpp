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

  string s; cin >> s;
  int n = s.size();
  if (n&1) {
    cout << "fix" << endl;
    return 0;
  }

  bool val = true;
  for (int i = 0; i < n/2; i++) {
    if (s[i] == '(') {
      if (i+1 != n-1-i || s[n-1-i] != ')') val = false;
    }
    else if (s[i] != s[n-1-i]) val = false; 
  }

  if (val) cout << "correct" << endl;
  else cout << "fix" << endl;
  
  return 0;
}
