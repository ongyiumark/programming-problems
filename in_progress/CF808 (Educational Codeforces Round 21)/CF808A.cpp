/*
  Change first digit.
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
  
  ll x; cin >> x;
  string s = to_string(x);
  string t = "";
  if (s[0] == '9') {
    t.append(1, '1');
    t.append((int)s.size(), '0');
  }
  else {
    t.append(1, s[0]+1);
    t.append((int)s.size()-1, '0');
  }

  ll y = stoll(t);
  cout << y-x << endl;

  return 0;
}
