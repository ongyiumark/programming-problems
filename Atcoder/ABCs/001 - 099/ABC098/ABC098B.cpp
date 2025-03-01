/*
  Try all possible splits and count.
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
  int n; cin >> n;
  string s; cin >> s;
  int ans = 0;
  for (int i = 1; i < n; i++){
    string a = s.substr(0, i);
    string b = s.substr(i);
    
    int seen_a = 0;
    for (char c : a){
      seen_a |= (1<<(c-'a'));
    }

    int seen_b = 0;
    for (char c : b){
      seen_b |= (1<<(c-'a'));
    }

    ans = max(ans, __builtin_popcount(seen_a&seen_b));
  }
  cout << ans << endl;
  return 0;
}
