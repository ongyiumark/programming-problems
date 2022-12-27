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

int n, m;
const int N = 1e5+5;
const ll LLINF = 4e18;
ll a[N];
ll d1[N];
ll d2[N];

void add_range(int l, int r, ll v, ll* d) {
  d[l] += v;
  d[r+1] -= v;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  memset(d1, 0, sizeof d1);
  memset(d2, 0, sizeof d2);

  for (int i = 1; i < n; i++) {
    if (a[i-1] < a[i]) {
      add_range(1, a[i-1], a[i]-a[i-1], d1);

      add_range(a[i-1]+1, a[i], a[i]+1, d1);
      add_range(a[i-1]+1, a[i], -1, d2);

      add_range(a[i]+1, m, a[i]-a[i-1], d1);
    }
    else {
      add_range(1, a[i], a[i]+1, d1);
      add_range(1, a[i], -1, d2);

      add_range(a[i]+1, a[i-1], a[i]-a[i-1]+m, d1);

      add_range(a[i-1]+1, m, a[i]+m+1, d1);
      add_range(a[i-1]+1, m, -1, d2);
    }
  }

  for (int i = 1; i <= m; i++) {
    d1[i] += d1[i-1];
    d2[i] += d2[i-1];
  }

  ll ans = LLINF; 
  for (ll i = 1; i <= m; i++) {

    ans = min(d1[i] + i*d2[i], ans);
  }
  cout << ans << "\n";
  return 0;
}
