/*
  We can write the line of MOOKs and MEEKs as a binary number.
  If we let MOOKs be 1 and MEEKs be 0, notice that every time Kim defeats a MOOK, we subtract the binary number by 1.
  The fight ends when the number becomes 0.

  So, the answer is the binary number of the original sequence.
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
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; i++){
      string s; cin >> s;
      if (s == "MOOK") ans |= (1LL << i);
    }
    cout << ans << endl;
  }
  return 0;
}
