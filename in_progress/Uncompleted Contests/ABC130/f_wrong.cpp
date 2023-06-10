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

  ld L = 0;
  ld R = 1e9;
  ld ans = 1e18;

  ll iter = 0;
  ll max_iter = 1000;

  while(iter <= max_iter) {
    ld m1 = (2*L + R)/3;
    ld m2 = (L + 2*R)/3;

    ld m1_ans = solve(m1);
    ld m2_ans = solve(m2);

    if (m1_ans < m2_ans) R = m2;
    else L = m1;

    ans = min({ans, m1_ans, m2_ans});
    iter++;
  }

  cout << fixed << setprecision(11) << ans << endl;

  return 0;
}
