/*
  Just check if theres sounds other than BEEP and BOOP.
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
  int c; cin >> c;
  while(c--){
    int n; cin >> n;
    bool bop = 1;
    for (int i = 0; i < n; i++){
      string s; cin >> s;
      if (s != "BEEP" && s != "BOOP") bop = 0;
    }
    cout << (bop ? "IT'S A BOP!" : "IT'S NOT A BOP!") << endl;
  }
  return 0;
}
