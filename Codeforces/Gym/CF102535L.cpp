/*
  It's optimal to swap the farthest MOOK with the closest MEEK.
  If we have extra swaps, we simply swap a MOOK with a MOOK or a MEEK with a MEEK.
  The exeption to this is when n = 2. In this edge case, we're forced to swap.

  Simply keep track of the locations of the MOOKs and MEEKs. Swap accordingly. 
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

const ll MOD = 1e9;
const int N = 1e5;
bool a[N];
vector<int> zeros, ones;

ll modpow(ll b, ll e){
  ll ans = 1;
  while(e > 0){
    if (e&1) ans = (ans*b)%MOD;
    b = (b*b)%MOD;
    e >>= 1;
  }
  return ans;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k; cin >> n >> k;
  for (int i = 0; i < n; i++){
    string s; cin >> s;
    a[i] = (s == "MOOK");
    if (a[i]) ones.push_back(i);
    else zeros.push_back(i);
  }

  reverse(ones.begin(), ones.end());
  int m = min({(int)ones.size(), (int)zeros.size(), k});
  int cnt = 0;
  for (int i = 0; i < m; i++){
    if (ones[i] < zeros[i]) break;
    swap(a[zeros[i]], a[ones[i]]);
    cnt++;
  }
  
  k -= cnt;
  if (n == 2 && k&1) swap(a[0], a[1]);
  ll ans = 0;
  for (int i = 0; i < n; i++){
    if (a[i]) ans = (ans + modpow(2,i))%MOD;
  }
  cout << ans << endl;
  return 0;
}
