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

ostream& operator<<(ostream& os, __float128 x) { return os << (long double)x; }

string s = "DURL";
int di[] = {0, 0, 1, -1};
int dj[] = {-1, 1, 0, 0};

const int N = 1e5+5;
const ll INF = 1e9;
const int MXITER = 100;
int n;

const ld EPS = 1e-9;
const ld DELTA = 1e-8;

vector<ll> x(N), y(N), d(N);  
vector<ld> solve(ld t) {
  ld x_lo, x_hi, y_lo, y_hi;
  x_lo = y_lo = INF;
  x_hi = y_hi = -INF;
  for (int i = 0; i < n; i++) {
    x_lo = min(x_lo, x[i]+di[d[i]]*t);
    x_hi = max(x_hi, x[i]+di[d[i]]*t);

    y_lo = min(y_lo, y[i]+dj[d[i]]*t);
    y_hi = max(y_hi, y[i]+dj[d[i]]*t);
  }

  return {x_lo, x_hi, y_lo, y_hi};
}

void get_times(vector<ld> &times) {
  ld lo, hi; int iter;
  for (int k = 0; k < 4; k++) {
    lo = 0;
    hi = 1e9;
    iter = MXITER;
    while(iter--) {
      ld mid = (lo+hi)/2;
      vector<ld> vals1 = solve(mid);
      vector<ld> vals2 = solve(mid+DELTA);
      
      if (k%2 == 0) {
        if (vals1[k]-EPS < vals2[k]) lo = mid;
        else hi = mid;
      }
      else {
        if (vals1[k] > vals2[k]-EPS) lo = mid;
        else hi = mid;
      }
    }
    times.push_back(lo);

    lo = 0;
    hi = 1e9;
    iter = MXITER;
    while(iter--) {
      ld mid = (lo+hi)/2;
      vector<ld> vals1 = solve(mid);
      vector<ld> vals2 = solve(mid+DELTA);
      
      if (k%2 == 0) {
        if (vals1[k] > vals2[k]-EPS) hi = mid;
        else lo = mid;
      }
      else {
        if (vals1[k]-EPS < vals2[k]) hi = mid;
        else lo = mid;
      }
    }
    times.push_back(lo);
  }
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

  vector<ld> times;
  get_times(times);

  ld area = 1e18;
  for (ld t : times) {
    vector<ld> vals = solve(t);
    area = min(area, (vals[1]-vals[0])*(vals[3]-vals[2]));
    if (fabs(vals[1]-vals[0]) <= DELTA || fabs(vals[3]-vals[2]) <= DELTA) area = 0;
  }

  cout << fixed << setprecision(11) << area << endl;

  return 0;
}
