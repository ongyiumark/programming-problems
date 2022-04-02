#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<int,pair<int,int>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll M = 1e9+7;
const ll N = 505;

ll mgcd(ll a, ll b){
  if (b==0) return a;
  return mgcd(b, a%b);
}

ll mlcm(ll a, ll b) {
  return a/mgcd(a,b)*b;
}

ll modpow(ll b, ll e){
  ll ans = 1;
  while (e > 0) {
    if (e&1) ans = ans*b%M;
    b = b*b%M;
    e >>= 1;
  }
  return ans;
}

ll inv(ll x) {
  return modpow(x, M-2);
}

ll comb[N][N];
ll pow2[N];

pii reduce(pii x) {
  return {x.first%M, x.second%M};
}

pii operator+ (pii const &left, pii const &right){
  ll L = mlcm(left.second, right.second);
  pii ans = {L/left.second*left.first + L/right.second*right.first, L};
  return reduce(ans);
}

pii operator*(ll const &left, pii const &right) {
  pii ans = {left*right.first, right.second};
  return reduce(ans);
}

pii dp[N][N];
pii solve(int acnt, int bcnt) {
  if (acnt == 0 || bcnt == 0) return {0,1};
  if (acnt > bcnt) swap(acnt,bcnt);
  if (dp[acnt][bcnt].first != -1) return dp[acnt][bcnt];
  ll n = acnt+bcnt;
  pii num = {pow2[n], 1};
  for (int i = 1; i < max(acnt,bcnt); i++) {
    if (i < acnt) num = num + comb[acnt][i]*solve(acnt-i,bcnt);
    if (i < bcnt) num = num + comb[bcnt][i]*solve(acnt,bcnt-i);
  }
  num = reduce(num);
  ll den = (pow2[acnt]+pow2[bcnt]-3)%M;
  if (den < 0) den += M;
  return dp[acnt][bcnt]= {num.first%M, num.second*den%M};
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  pow2[0] = 1;
  for (int i = 1; i < N; i++) pow2[i] = pow2[i-1]*2%M;

  memset(comb, 0, sizeof 0);
  for (int i = 0; i < N; i++){
    for (int j = 0; j <= i; j++) {
      if (j == 0) comb[i][j] = 1;
      else comb[i][j] = (comb[i-1][j-1] + comb[i-1][j])%M;
    }
  }

  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      dp[i][j] = {-1,-1};
    }
  }

  int n; cin >> n;
  string a, b;
  cin >> a >> b;
  int acnt, bcnt;
  acnt = bcnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 'B' && b[i] == 'G') acnt++;
    if (a[i] == 'G' && b[i] == 'B') bcnt++;
  }

  pii ans = solve(acnt, bcnt);
  cout << ans.first*inv(ans.second)%M << endl;
  return 0;
}
