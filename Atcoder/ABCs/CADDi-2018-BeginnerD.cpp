/*
  It's a classic nim game, but sideways.
  Imagine having gravity to the left. It becomes the classic nim game.
  We just need to xor smartly since we can't store 1e9 numbers.

  We use the fact that x^x = 0. So, we just need to include heights with odd towers.
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
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a+n);

  ll ans = 0;
  ll last = 0;
  for (int i = 0; i < n; i++){
    ll next = a[i]-last;
    if (next&1) ans ^= n-i;
    last = a[i];
  }
  cout << (ans != 0 ? "first" : "second") << endl;
  return 0;
}
