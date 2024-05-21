/*
  5e15 is so large that the first number that is not 1 will dominate the entire string all the way up to the 1e18-th character.
  So, the answer is either 1 or the first number that is not 1.
  Just check if k is before the first occurence of a number that is not 1.
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
  ll k; cin >> k;
  int not_one = 0;
  while(not_one < s.size() && s[not_one] == '1') not_one++;
  if (k <= not_one) cout << 1 << endl;
  else cout << s[not_one] << endl;
  return 0;
}
