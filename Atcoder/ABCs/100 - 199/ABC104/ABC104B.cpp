/*
  Long but straightforward instructions.
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
  
  string s; cin >> s;
  int n = s.size();
  bool valid = 1;
  if (s[0] != 'A') valid = 0;
  
  int cidx = -1;
  int ccnt = 0;
  for (int i = 2; i < n-1; i++){
    if (s[i] == 'C') {
      cidx = i;
      ccnt++;
    }
  }
  if (ccnt != 1) valid = 0;
  for (int i = 1; i < (int)s.size() && valid; i++){
    if (s[i] == 'C') continue;
    if (!(s[i] >= 'a' && s[i] <= 'z')) valid = 0;
  }
  cout << (valid ? "AC" : "WA") << endl;
  return 0;
}
