/*
  Spam 2 and 1 alternating.
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

void testcase(){
  int n; cin >> n;
  vector<int> ans;
  if (n%3 == 0) {
    for (int i = 0; i < n/3; i++){
      ans.push_back(2);
      ans.push_back(1);
    }
  }
  else if (n%3 == 1) {
    ans.push_back(1);
    for (int i = 0; i < n/3; i++){
      ans.push_back(2);
      ans.push_back(1);
    }
  }
  else {
    for (int i = 0; i < n/3; i++){
      ans.push_back(2);
      ans.push_back(1);
    }
    ans.push_back(2);
  }
  for (int v : ans) {
    cout << v;
  }
  cout << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while(t--) {
    testcase();
  }
  return 0;
}
