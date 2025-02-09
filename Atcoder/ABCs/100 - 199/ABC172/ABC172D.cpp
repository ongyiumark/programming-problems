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

  int n; cin >> n;
  vector<int> p;
  vector<bool> isc(n+1);

  vector<ll> div(n+1);
  vector<int> pcnt(n+1);
  
  // linear sieve
  div[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!isc[i]) {
      p.push_back(i);
      div[i] = 2;
      pcnt[i] = 1;
    }
    for (int j = 0; j < (int)p.size() and i*p[j] <= n; j++) {
      isc[i*p[j]] = true;
      if (i % p[j] == 0) {
        pcnt[i*p[j]] = pcnt[i]+1;
        div[i*p[j]] = div[i]/(pcnt[i]+1)*(pcnt[i*p[j]]+1);
        break;
      }
      else {
        div[i*p[j]] = div[i]*div[p[j]];
        pcnt[i*p[j]] = 1;
      }
    }
  }
  
  ll ans = 0;
  for (ll k = 1; k <= n; k++) ans += k * div[k];
  cout << ans << "\n";
  return 0;
}
