/*
  Add 2 to the to each number until it's equal to or 1 less than the maximum number.
  There's two possibilities after this:
    If there is only one number that is less than the maximum, it'll take 2 more moves.
    If there are two numbers that are less than the maximum, it'll take 1 more move.
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
  int a, b, c; cin >> a >> b >> c;
  int hi = max({a,b,c});
  int ans = (hi-a)/2 + (hi-b)/2 + (hi-c)/2;
  int cnt = (hi-a)%2 + (hi-b)%2 + (hi-c)%2;

  if (cnt == 1) ans += 2;
  else if (cnt == 2) ans += 1;

  cout << ans << endl;
  return 0;
}
