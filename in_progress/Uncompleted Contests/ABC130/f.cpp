// Ternary Search but apparently this is wrong.

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

string s = "DURL";
int di[] = {0, 0, 1, -1};
int dj[] = {-1, 1, 0, 0};

const int N = 1e5+5;
vector<ll> x(N), y(N), d(N);
const ll INF = 1e9;
int n;

const ld EPS = 1e-9;

ld solve(ld t) {
  ld x_lo, x_hi, y_lo, y_hi;
  x_lo = y_lo = INF;
  x_hi = y_hi = -INF;
  for (int i = 0; i < n; i++) {
    x_lo = min(x_lo, x[i]+di[d[i]]*t);
    x_hi = max(x_hi, x[i]+di[d[i]]*t);

    y_lo = min(y_lo, y[i]+dj[d[i]]*t);
    y_hi = max(y_hi, y[i]+dj[d[i]]*t);
  }

  return (y_hi - y_lo)*(x_hi - x_lo);
}

pair<ld,ld> min_max(vector<ll> &z, int *dz, ld t) {
  ld x_lo, x_hi;
  x_lo = INF; x_hi = -INF;
  for (int i = 0; i < n; i++) {
    x_lo = min(x_lo, z[i]+dz[d[i]]*t);
    x_hi = max(x_hi, z[i]+dz[d[i]]*t);
  }

  return {x_lo, x_hi};
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n;
  unordered_map<char, int> um;
  for (int d = 0; d < 4; d++) um[s[d]] = d;

  for (int i = 0; i < n; i++) {
    char c; cin >> x[i] >> y[i] >> c;
    d[i] = um[c];
  }

  

 

  cout << fixed << setprecision(11) << ans << endl;

  return 0;
}
