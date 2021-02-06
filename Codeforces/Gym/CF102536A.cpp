/* 
  Normal Levenshtein distance, but have a limit on the recursion depth by limiting the distance.
  Apparently, you don't need to memoize this. 
  It'll run in O(3^4(|n|+|m|))
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

string s, u;
int solve(int i, int j, int d){
  int ret = 4;
  if (d > 3) return 4;
  if (i < 0 && j < 0){
    return d;
  }
  if (s[i] == u[j]) {
    if (i >= 0 && j >= 0) return solve(i-1,j-1,d);
  }
  else {
    if (i >= 0 && j >= 0) ret = min(ret, solve(i-1,j-1,d+1));
    if (i >= 0) ret = min(ret,solve(i-1, j, d+1));
    if (j >= 0) ret = min(ret,solve(i, j-1, d+1));
  }
  return ret;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--){
    cin >> s >> u;
    int d = solve((int)s.size()-1,(int)u.size()-1,0);
    if (d == 0) cout << "You're logged in!";
    else if (d == 1) cout << "You almost got it. You're wrong in just one spot.";
    else if (d == 2) cout << "You almost got it, but you're wrong in two spots.";
    else if (d == 3) cout << "You're wrong in three spots.";
    else cout << "What you entered is too different from the real password.";
    cout << endl;
  }
  return 0;
}
