/*
  The constraints are small enough to check all substrings.
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

bool check(string s){
  for (char c : s){
    if (c != 'A' && c != 'T' && c != 'C' && c != 'G') return false;
  }
  return true;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s; cin >> s;
  int n = s.size();
  for (int len = n; len >= 0; len--){
    for (int i = 0; i + len - 1 < n; i++){
      string t = s.substr(i, len);
      if (check(t)) {
        cout << len << endl;
        return 0;
      }
    }
  }

  return 0;
}
