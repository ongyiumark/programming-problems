/*
  Either start with 0 or start with 1.
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

string s; 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> s;
  int n = s.size();

  int ans1, ans2;
  ans1 = ans2 = 0;
  for (int i = 0; i < n; i++){
    if ((s[i] == '0')^(i%2)) ans1++;
    if ((s[i] == '1')^(i%2)) ans2++; 
  }
  cout << min(ans1, ans2) << endl;
  return 0;
}
