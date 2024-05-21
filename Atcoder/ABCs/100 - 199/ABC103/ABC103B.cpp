/*
  Duplicate s and check of t is a subtring of that.
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
  string s, t; cin >> s >> t;
  s += s;
  int n = t.size();
  for (int i = 0; i+n-1 < 2*n ; i++){
    bool val = 1;
    for (int j = 0; j < n; j++){ 
      val &= (s[i+j] == t[j]);
    }
    if (val) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
