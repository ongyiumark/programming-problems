/*
  The numbers have to be the same, so just count the possible ways to choose those 3 numbers.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5+5;
ll a[N];

ll comb(ll n, ll k) {
  ll num = 1;
  for (int i = n; i > n-k; i--) {
    num *= i;
  }

  ll den = 1;
  for (int i = 1; i <= k; i++) {
    den *= i;
  }

  return num/den;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  for (int i= 0; i < n; i++) cin >> a[i];
  sort(a, a+n);

  ll num = a[0]*a[1]*a[2];
  map<int,int> og, cnt;
  for (int i = 0; i < 3; i++) og[a[i]]++;
  for (int i = 0; i < n; i++) cnt[a[i]]++;

  ll ans = 1;
  for (auto it : og) {
    ans *= comb(cnt[it.first], it.second);
  }

  cout << ans << endl;

  return 0;
}
