/*
  Try all substrings of length less than or equal to 5.
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

ordered_set<string> subs;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  string s; cin >> s;
  int k; cin >> k;
  int n = s.size();
  for (int i = 0; i < n; i++){
    for (int len = 1; len+i <= n && len <= 5; len++){
      subs.insert(s.substr(i, len));
    }
  }
  cout << *subs.find_by_order(k-1) << endl;
  return 0;
}
