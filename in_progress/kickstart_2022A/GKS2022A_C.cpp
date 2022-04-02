/*
  Notice that we only need to check length 5 and length 6 palindromes.
  Just brute force with pruning.
  This will be fast enough because of some magical state analysis.
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

int n;
string s;
vector<char> tmp;

bool solve(int idx){
  // check last 5
  if (idx >= 5) {
    bool palin = true;
    for (int i = 0; i < 2; i++){
      if (tmp[idx-5+i] != tmp[idx-i-1]) {
        palin = false;
      }
    }
    if (palin) return false;
  }
  // check last 6
  if (idx >= 6) {
    bool palin = true;
    for (int i = 0; i < 3; i++){
      if (tmp[idx-6+i] != tmp[idx-i-1]) {
        palin = false;
      }
    }
    if (palin) return false;
  }

  if (idx == n) return true;

  bool ans = false;
  if (s[idx] != '?'){
    tmp.push_back(s[idx]);
    ans |= solve(idx+1);
    tmp.pop_back();
  }
  else {
    for (char c : {'0','1'}){
      tmp.push_back(c);
      ans |= solve(idx+1);
      tmp.pop_back();
    }
  }
  return ans;
}
// we only care about palindromes of lengths 5 and 6.
void testcase(){
  tmp.clear();
  cin >> n >> s;
  if (n < 5) {
    cout << "POSSIBLE" << endl;
    return;
  }
  cout << (solve(0) ? "POSSIBLE" : "IMPOSSIBLE") << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int T; cin >> T;
  for (int x = 1; x <= T; x++) {
    cout << "Case #" << x << ": ";
    testcase();
  }

  return 0;
}
