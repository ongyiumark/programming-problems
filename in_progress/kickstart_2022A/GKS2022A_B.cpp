/*
  Sum of digits have to be divisible by 9, so you can compute the digit you need to add.
    Edge case: Add '0'. Don't add '9'.
  Add the digit d before the first occurence of the a digit that is greater than d.
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

string n;
void testcase(){
  cin >> n;
  int total = 0;
  for (char ch : n){
    total += ch-'0';
  }
  total %= 9;
  if (total == 0) total += 9;
  char need = '0'+9-total;
  bool done = false;
  for (int i = 0; i < n.size(); i++){
    char ch = n[i];
    if (need == '0' && i == 0) {
      cout << ch;
      continue;
    }
    if (need < ch && !done){
      cout << need;
      done = true;
    }
    cout << ch;
  }
  if (!done) cout << need;
  cout << endl;
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
