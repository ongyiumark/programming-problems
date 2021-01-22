/*
  Suppose the only constraint is that the maximum speed is v between l and r.
  To maximize the distance traveled, we accelerate by 1 m/s^2 as we move away from l and r.
  \      / Something like this.
   \____/

  We do this for every constraint. This includes a maximum speed of 0 at the beginning and at the end.
  We then get the minimum of speed for every second.

  To get the area under the curve, we can just add the velocities at each second.
  This works because we start at 0 and end at 0, so the number of ups is equal to the number of downs.
  The overestimates are compensated exactly by the underestimates.

  However, there is a problem when the lines don't meet at integral points. 
  To fix this, we multiply the time and velocity both by 2, and divide the total area by 4. 
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

const int N = 105;
int t[N], v[N];
int tans[N][N*400];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  int total = 0;
  for (int i = 1; i <= n; i++){
    cin >> t[i];
    t[i] *= 2;
    total += t[i];
  }
  for (int i = 1; i <= n; i++){
    cin >> v[i];
    v[i] *= 2;
  }
  t[0] = t[n+1] = v[0] = v[n+1] = 0;

  int l = 0;
  for (int i = 0; i <= n+1; i++){
    int r = l+t[i];
    for (int j = 0; j <= total; j++){
      if (j < l) tans[i][j] = v[i]+(l-j);
      else if (j > r) tans[i][j] = v[i]+(j-r);
      else tans[i][j] = v[i]; 
    }
    l = r;
  } 

  int ans = 0;
  for (int j = 0; j <= total; j++){
    int res = 1e9;
    for (int i = 0; i <= n+1; i++){
      res = min(res, tans[i][j]);
    }
    ans += res;
  }

  cout << setprecision(6) << fixed << (ld)ans/4 << endl;
  return 0;
}
