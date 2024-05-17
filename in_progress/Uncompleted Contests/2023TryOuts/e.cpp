#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m; cin >> n >> m;
  bool forward[n][1005], backward[n][1005];
  memset(forward, sizeof forward, 0);
  memset(backward, sizeof backward, 0);
  for (int i = 1; i <= m; i++) {
    int a; cin >> a;
    a--;
    forward[a][i] = true;
    backward[a+1][i] = true;
  }

  vector<int> res(n);
  for (int x = 0; x < n; x++) {
    int cx = x;
    for (int i = 1; i <= m; i++) {
      if (forward[cx][i]) cx++;
      else if (backward[cx][i]) cx--;
    }
    res[cx] = x;
  }
  for (int i = 0; i < n; i++) {
    cout << res[i]+1 << "\n";
  }

  
  return 0;
}
