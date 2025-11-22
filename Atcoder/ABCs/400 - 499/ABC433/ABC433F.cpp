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
const int MAXN = 2e6+5;
vector<ll> fact(MAXN), ifact(MAXN);
ll mod_pow(ll b, ll e) {
  ll ans = 1;
  while (e > 0) {
    if (e&1) ans = ans*b%MOD;
    b = b*b%MOD;
    e >>= 1;
  }
  return ans;
}

ll mod_inv(ll x) {
  return mod_pow(x, MOD-2);
}

ll perm(ll n, ll k) {
  return fact[n]*ifact[n-k]%MOD;
}

ll choose(ll n, ll k) {
  if (n < k) return 0;
  return perm(n, k)*ifact[k]%MOD;
}

int main(){
  cin.tie(0)->sync_with_stdio(false);
  fact[0] = 1;
  for (int i = 1; i < MAXN; i++) fact[i] = fact[i-1]*i%MOD;
  ifact[MAXN-1] = mod_inv(fact[MAXN-1]);
  for (int i = MAXN-2; i >= 0; i--) ifact[i] = ifact[i+1]*(i+1)%MOD;


  string s; cin >> s;
  int n = s.size();
  vector<vector<int>> count_left(10, vector<int>(n, 0)), count_right(10, vector<int>(n, 0));
  for (int k = 0; k < 10; k++) {
    for (int i = 0; i < n; i++) {
      count_left[k][i] = (s[i]-'0' == k);
      if (i > 0) count_left[k][i] += count_left[k][i-1];
    }
    for (int i = n-1; i >= 0; i--) {
      count_right[k][i] = (s[i]-'0' == k);
      if (i < n-1) count_right[k][i] += count_right[k][i+1];
    }
  }

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i]-'0' == 9) continue;
    int left_count = count_left[s[i]-'0'][i];
    int right_count = count_right[s[i]-'0'+1][i];
    if (right_count == 0) continue;

    // let p = left_count, q = right_count
    // sum over j >= 1 of choose(p-1, j-1)*choose(q, j)
    // sum over j >= 1 of choose(p-1, j-1)*choose(q, q-j)
    // sum over k_1 + k_2 = q-1 of choose(p-1, k_1)*choose(q, k_2)
    // coef of x**(q-1) in (1+x)**(p-1) * (1+x)**q 
    // coef of x**(q-1) in (1+x)**(p+q-1)
    // choose(p+q-1, q-1)
    ll current = choose(left_count+right_count-1, right_count-1);

    ans = (ans+current)%MOD;
  }

  cout << ans << "\n";
  return 0;
}
