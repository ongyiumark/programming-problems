/*
  Just try all numbers N and above.
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
  
  int n, k; cin >> n >> k;
  vector<bool> val(10);
  for (int i = 0; i < k; i++) {
    int d; cin >> d;
    val[d] = 1;
  }
  while(1){
    string s = to_string(n);
    bool valid = 1;
    for (char ch : s) {
      if (val[ch-'0']) valid = 0;
    }

    if (valid) break;
    n++;
  }
  cout << n << endl;
  return 0;
}
