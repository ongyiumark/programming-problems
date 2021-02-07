/*
  You always want to touch the first character that hasn't been touched.
  If you're alice, you want to change the letter to 'a'. If it's already 'a', then change it to 'b'.
  If you're bob, you want to change the letter to 'z'. If it's already 'z', then change it to 'y'.
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
  int t; cin >> t;
  while(t--){
    string s; cin >> s;
    bool alice = 1;
    for (char &c : s){
      if (alice) {
        if (c == 'a') c = 'b';
        else c = 'a';
      }
      else {
        if (c == 'z') c = 'y';
        else c = 'z';
      }
      alice = !alice;
    }

    cout << s << endl;
  }
  return 0;
}
