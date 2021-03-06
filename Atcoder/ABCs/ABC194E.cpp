/*
  I used a set to keep track of numbers that are currently not in the mex set.
  Then, I added and removed number from the set at each 0 <= i < n-m.
  To decide whether to add a number, we need to know if that number appears within the next m elements.
    We can do this by precomputing the index of the next occurence of a number.
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

const int N = 1.5e6;
int a[N+5], nxt[N+5], lastseen[N+5];
set<int> mex;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }

  memset(nxt, -1, sizeof nxt);
  memset(lastseen, -1, sizeof lastseen);
  for (int i = n-1; i >= 0; i--){
    if (lastseen[a[i]] == -1) nxt[i] = n;
    else nxt[i] = lastseen[a[i]];
    lastseen[a[i]] = i;
  }

  for (int i = 0; i <= n; i++) mex.insert(i);
  for (int i = 0; i < m; i++) {
    if (mex.find(a[i]) != mex.end()) mex.erase(a[i]);
  }
  int ans = *mex.begin();
  for (int i = 0; i < n-m; i++){
    if (nxt[i] >= i+m) mex.insert(a[i]);
    if (mex.find(a[i+m]) != mex.end()) mex.erase(a[i+m]);
    ans = min(ans, *mex.begin());
  }
  cout << ans << endl;
  return 0;
}
