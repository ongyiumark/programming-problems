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

bool is_palindrome(string s){
  int n = s.size();
  for(int i = 0; i < n/2; i++){
    if (s[i] != s[n-1-i]) return false;
  }
  return true;
}
void testcase(){
  int n, k; cin >> n >> k;
  string s; cin >> s;

  if (is_palindrome(s) || k == 0){
    cout << 1 << endl;
    return;
  }
  cout << 2 << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  for (int i = 0; i < t; i++){
    testcase();
  }
  return 0;
}
