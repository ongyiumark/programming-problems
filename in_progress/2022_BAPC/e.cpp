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

const ld EPS = 1e-6;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  

  ll n, x; cin >> n >> x;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  ll curr = 0;
  for (int i = 0; i < n; i++) {
    curr += a[i]*a[i];
  }
  ld nx = (ld)curr/(ld)n;


  cout << setprecision(20) << fixed;
  if (fabs(nx) < EPS) {
    for (int i = 0; i < n; i++) {
      cout << 0;
      if (i == n-1) cout << "\n";
      else cout << " ";
    }
  }
  else {
    ld mult = sqrtl((ld)x/nx);
    for (int i = 0; i < n; i++) {
      cout << mult*a[i];
      if (i == n-1) cout << "\n";
      else cout << " ";
    }
  }
  return 0;
}
