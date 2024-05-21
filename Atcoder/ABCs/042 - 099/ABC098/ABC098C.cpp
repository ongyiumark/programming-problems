/*
  Use prefix sums to count the number of easts and wests in a range.
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

const int N = 3e5;
int west[N], east[N];
string s;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  cin >> s;
  for (int i = 0 ; i < n; i++){
    west[i] = (s[i]=='W');
    east[i] = (s[i]=='E');
    if (i > 0){
      west[i] += west[i-1];
      east[i] += east[i-1];
    }
  }
  int ans = min(east[n-1]-east[0], west[n-2]);
  for (int i = 1; i < n-1; i++){
    ans = min(ans, west[i-1]+east[n-1]-east[i]);
  }
  cout << ans << endl;
  return 0;
}
