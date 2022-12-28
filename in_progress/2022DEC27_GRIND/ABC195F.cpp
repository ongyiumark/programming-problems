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

const int N = 100;
vector<int> p;
bitset<N> isc;

const int P = 21;
map<ii, ll> memo;
ll m[N];
int n;

ll solve(int i, int mask) {
  if (memo.find({i, mask}) != memo.end()) return memo[{i,mask}];
  ll &ans = memo[{i,mask}];
  if (i == n) return ans = 1;

  ans = solve(i+1, mask);
  if ((mask&m[i]) == 0) ans += solve(i+1, mask|m[i]);
  return ans;
}

void sieve() {
  for (int i = 2; i <= n; i++) {
    if (!isc[i]) p.push_back(i);
    for (int j = 0; j < (int)p.size() && p[j]*i <= n; j++) {
      isc.set(i*p[j]);
      if (i % p[j] == 0) break;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll a, b; cin >> a >> b;
  n = b-a+1;
  vector<ll> ar(n);
  for (int i = 0; i < n; i++) ar[i] = a+i;

  sieve();
  int psz = p.size();
  
  memset(m, 0, sizeof m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < psz; j++) {
      if (ar[i] % p[j] == 0) m[i] |= (1<<j);
    }
  }

  cout << solve(0, 0) << "\n";

  
  return 0;
}
