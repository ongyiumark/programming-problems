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
const int P = 1e4+5;
ll dp[N];
ll cnt[P];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, p;
  string s;
  cin >> n >> p >> s;

  memset(cnt, 0, sizeof cnt);
  memset(dp, 0, sizeof dp);

  if (p == 2 || p == 5) {
    ll total = 0;
    for (int i = 0; i < n; i++) {
      if ((s[i]-'0')%p == 0) {
        total += i+1;
      }
    }

    cout << total << "\n";
    return 0;
  }

  ll total = 0;
  dp[n+1] = 0;
  cnt[dp[n+1]]++;
  ll pow10 = 1;

  for (int i = n-1; i >= 0; i--) {
    dp[i] = ((s[i]-'0')*pow10 + dp[i+1])%p;
    
    total += cnt[dp[i]];
    cnt[dp[i]]++;
    pow10 = pow10*10%p;
  }

  cout << total << "\n";

 

  return 0;
}
