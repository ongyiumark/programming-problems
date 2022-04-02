/*
  This is one of those problems that you just have to know the answer.
  Turns out you can find a way to have the sum be 0.
  The number i has to be n-i away from each other.
  This means you can from a sequence this way:
    i i+2 ... i+2 i
  because if i are n-i away, then i+2 are n-4 away.

  Do this for odds and evens. 
  You'll be left with the number n, which you can put anywhere.
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
  vector<int> ans(2*n+1);
  for (int i = 1; i <= (n+1)/2; i++){
    ans[i] = 2*i-1;
    ans[n+1-i] = 2*i-1;
  }
  for (int i = 1; i <= n/2; i++) {
    ans[n+i] = 2*i;
    ans[n+n-i] = 2*i;
  }
  ans[2*n] = n;
  for (int i = 1; i <= 2*n; i++) {
    cout << ans[i];
    if (i == 2*n) cout << endl;
    else cout << " ";
  }
  return 0;
}
