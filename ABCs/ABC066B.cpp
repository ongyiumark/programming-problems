#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

bool is_even(string s){
  int n = s.size();
  if (n&1) return false;
  for (int i = 0; i < n/2; i++){
    if (s[i] != s[i+n/2]) return false;
  }
  return true;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s; cin >> s;
  int n = s.size();
  int i;
  for (i = n-1; i >= 0; i--){
    if(is_even(s.substr(0, i))) break;
  }
  cout << i << endl;
  return 0;
}
