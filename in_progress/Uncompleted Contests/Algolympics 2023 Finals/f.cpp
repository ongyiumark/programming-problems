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

const ll MOD = 998244353;

map<tuple<int,int,int>, ll> memo;
ll solve(ll a, ll n, ll pa) {
  if (memo.find({a,n,pa}) != memo.end()) return memo[{a,n,pa}];
  
  ll &ans = memo[{a,n,pa}];
  // number of ways to partition n into a parts, sorted 
  if (a == 0) return ans=(n==0);

  ans = 0;
  for (int i = pa; i <= n; i++) {
    ans += solve(a-1, n-i, i); 
    ans %= MOD;   
  }
  return ans;
}

ll f(ll a, ll c) {
  a = min(a, c-a);
  if (a == 0) return 1;
  return solve(a, c-2*a, 0);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll b; cin >> b;
  ll total = 0;
  for (ll d = 1; d <= b; d++) {
    if (b*b % d == 0) {
      ll tmp1 = d;
      ll tmp2 = b*b/d;

      if ((tmp1+tmp2)%2==1) continue;  
      ll c = (tmp1+tmp2)/2;
      ll a = (tmp2-tmp1)/2;

      total += f(a,c);
      total %= MOD;
    }
  }

  cout << total << "\n";
  
  return 0;
}
