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
const ll INF = 1e18;
pair<ll,ll> mon[N];
ll h[N], p[N];
ll suf[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while(t--) {
    ll n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
      cin >> h[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
      mon[i] = {h[i], p[i]};
    }

    sort(mon, mon+n);

    suf[n] = INF; 
    for (int i = n-1; i >= 0; i--) {
      suf[i] = min(suf[i+1], mon[i].second);
    }

    int j = 0;
    ll curr = k;
    while (k > 0 && j < n) {
      while(curr >= mon[j].first && j < n) j++;
      if (j == n) break;

      k -= suf[j];
      curr += k;
    }

    if (j == n) cout << "YES\n";
    else cout << "NO\n";
  }

  
  
  return 0;
}
