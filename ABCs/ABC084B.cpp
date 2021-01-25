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
  
  int a, b; cin >> a >> b;
  string s; cin >> s;
  bool valid = 1;
  if (a+b+1 != (int) s.size()) valid = 0;

  for (int i = 0; i < a; i++){
    if (!(s[i] >= '0' && s[i] <= '9')){
      valid = 0;
    }
  }
  if (s[a] != '-') valid = 0;
  for (int i = a+1; i < a+b+1; i++){
    if (!(s[i] >= '0' && s[i] <= '9')){
      valid = 0;
    }
  }
  cout << (valid ? "Yes" : "No") << endl;
  return 0;
}
