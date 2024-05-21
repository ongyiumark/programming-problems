/*
  Go through the sequence until you reach 2.
  You can never reach 2 if you revisit a number.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5;
int a[N+1];
bool vis[N+1];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  for (int i = 1; i <= n; i++){
    cin >> a[i];
  }
  
  int x = 1;
  int cnt = 0;
  while(x != 2){
    if (vis[x]) break;
    vis[x] = true;
    x = a[x];
    cnt++;
  }

  if (x == 2) cout << cnt << endl;
  else cout << -1 << endl;
  return 0;
}
