/*
  First check if the height or width is divisible by 3. If it is, the answer is 0.
  Two slices in the same direction will have max-min = w or max-min = h.
  Try all slices in 1 direction, then slice the other portion in half in the other direction.
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

ll solve(ll h, ll w){
  if (h%3 == 0 || w%3 == 0) return 0;
  ll ans = min(h, w);

  for (int i = 1; i < h; i++){
    ll a = i*w;
    ll b = (w+1)/2 * (h-i);
    ll c = w/2 * (h-i);
    ans = min(ans, max({a,b,c})- min({a,b,c}));
  }
  for (int i = 1; i < w; i++){
    ll a = i*h;
    ll b = (h+1)/2 * (w-i);
    ll c = h/2 * (w-i);
    ans = min(ans, max({a,b,c})- min({a,b,c}));
  }
  return ans; 
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll h, w; cin >> h >> w;
  cout << solve(h,w) << endl;
  return 0;
}
