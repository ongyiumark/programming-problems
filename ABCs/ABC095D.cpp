/*  
  Notice that Nakahashi must not skip any sushi he passes by.
  So, the optimal sushi he eats must lie on a contiguous segment.

  The optimal way to walk this segments is to:
    (1) Walk clockwise until you reach one end of the segment then walk counterclockwise.
    (2) Walk counterclockwise until you reach one end of the segment then walk clockwise.
  
  Case 1:
  Let's handle the clockwise and counter clockwise separately.

  First, we sort by distance.
  Suppose we end at the i-th sushi clockwise, the nutrition value would be the sum of the sushi we passed minus x[i].
  However, we would need to retrace our path back to the origin, so thats another minus x[i].
  Thus, the value would be sum[i]-2*x[i].

  For the counterclockwise case, we change x[i] := c-x[i] and sort again.
  Then, suppose we end at the j-th sushi counterclockwise, 
  The nutrition value would be the sum of the sushi we passed minus x[j].
  Thus, the value would be sum[j]-x[j].
  
  We can maintain prefix maximums to compute the optimal answer.
  If we end at the i-th sushi clockwise, we must end at most at the (n-i-2)-th sushi counterclockwise so as not to double count. 

  So, the answer would be the maximum of clockwise[i]+counterclockwise[n-i-2] for all i.

  Case 2 is handled similarly.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<int,pair<int,int>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector<pii> sushi_cw, sushi_ccw;
vector<pii> cw, ccw;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll n, c;
  cin >> n >> c;
  for (int i = 0; i < n; i++){
    ll x, v; cin >> x >> v;
    sushi_cw.push_back({x,v});
    sushi_ccw.push_back({c-x,v});
  }
  sort(sushi_cw.begin(), sushi_cw.end());
  sort(sushi_ccw.begin(), sushi_ccw.end());

  ll total_cw, total_ccw;
  ll cwa, cwb, ccwa, ccwb;
  total_cw = total_ccw = cwa = cwb = ccwa = ccwb = 0;
  for (int i = 0; i < n; i++){
    total_cw += sushi_cw[i].second;
    cwa = max(cwa, total_cw-sushi_cw[i].first);
    cwb = max(cwb, total_cw-sushi_cw[i].first*2);

    total_ccw += sushi_ccw[i].second;
    ccwa = max(ccwa, total_ccw-sushi_ccw[i].first);
    ccwb = max(ccwb, total_ccw-sushi_ccw[i].first*2);

    cw.push_back({cwa, cwb});
    ccw.push_back({ccwa, ccwb});
  }

  ll ans = max(cw[n-1].first, ccw[n-1].first);
  for (int i = 0; i < n-1; i++){
    ans = max({ans, cw[i].first+ccw[n-i-2].second, ccw[i].first+cw[n-i-2].second});
  }
  cout << ans << endl;
  return 0;
}
