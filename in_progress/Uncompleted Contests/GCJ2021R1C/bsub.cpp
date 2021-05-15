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

ll y;

bool check(ll y){
  string s = to_string(y);
  int n = s.size();
  for (int i = 1; 2*i <= n; i++){
    int pos = 0;
    string t = s.substr(pos, i);
    int x = stoll(t);
    pos += i;
    
    while(true){
      x++;
      string strx = to_string(x);
      int len = strx.size();
      if (n-pos < len) break;
      t = s.substr(pos, len);
      if (strx != t) break;
      pos += len;
      if (pos == n) return true;
    }
  }
  return false;
}
void testcase(){
  cin >> y;
  if (y > 1e6) {
    cout << 0 << endl;
    return;
  }

  y++;
  while(!check(y)) y++;
  cout << y << endl;
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
