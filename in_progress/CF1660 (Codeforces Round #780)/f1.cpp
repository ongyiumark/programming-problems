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
int n;

void testcase() {
  cin >> n;
  cin >> s;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int plus = 0;
    int minus = 0;
    for (int j = i; j < n; j++) {
      plus += (s[j] == '+');
      minus += (s[j] == '-');

      if (plus > minus) continue;
      int diff = minus-plus;
      if (diff == 0 || (diff >= 3 && diff%2 == 1)) ans++;
    }
  }
  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while(t--){
    testcase();
  }
  return 0;
}
