/*
  Greedy solution.
  Let x be the end of the first set and let y be the end of the second set.
  Let z be the current number we want to append.
  If z is equal to one of x or y, then append it to the one thats not equal.
    If they're both equal, it doesn't matter.

  If z is not equal to x and y, then append z to the set that appears first.
    That is, if the next appearance of x occurs before y, then append z to the set that ends in x.
  
  The proof for this is some complicated exchange argument.
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

const int N  = 1e5+5;
int a[N], nxt[N];
int tmp[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  memset(a, 0, sizeof a);
  for (int i = 1; i <= n; i++) cin >> a[i];

  memset(tmp, 63, sizeof tmp);
  for (int i = n; i >= 0; i--){
    nxt[i] = tmp[a[i]];
    tmp[a[i]] = i; 
  }

  int s,t;
  s = t = 0;
  int ans = 0;
  for (int i = 1; i <= n; i++){
    if (a[s] == a[i] || a[t] == a[i]){
      if (a[s] != a[i] || a[t] != a[i]) ans++;
      // append to the one thats not equal
      if (a[s] == a[i]) t = i;
      else s = i;
    }
    else{
      ans++;
      // append to the nearest
      if (nxt[s] < nxt[t]) s = i;
      else t = i;
    }
  }
  cout << ans << endl;
  return 0;
}
