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

const int N = 2e5+5;
pair<ll,ll> xh[N];
ll diff[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll n, d, a; cin >> n >> d >> a;
  for (int i = 0; i < n; i++) cin >> xh[i].first >> xh[i].second;

  sort(xh, xh + n);
  memset(diff, 0, sizeof diff);

  int i = 0, j = 0;
  ll ans = 0;
  while(i < n || j < n) {
    while (j < n && xh[j].first <= xh[i].first+2*d) {
      j++;
    }
    
    ll tmp = (xh[i].second-diff[i]+a-1)/a;
    diff[i] += tmp*a;
    diff[j] -= tmp*a;
    ans += tmp;

    while(i < n && xh[i].second <= diff[i]) {
      diff[i+1] += diff[i];
      i++;
    }
    if (j < i) j = i;
  }

  cout << ans << "\n";
  return 0;
}
