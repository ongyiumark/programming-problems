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

const int N = 2e5+5;
ll x[N], y[N];
set<pii> track;
int n;

pii valid(ll i, ll j, ll x){
  for (int k = 0; k <= x; k++) {
    if (track.find({i+k,j+x-k}) == track.end()) return {i+k, j+x-k};
    if (track.find({i-k,j+x-k}) == track.end()) return {i-k, j+x-k};
    if (track.find({i+k,j-x+k}) == track.end()) return {i+k, j-x+k};
    if (track.find({i-k,j-x+k}) == track.end()) return {i-k, j-x+k};
  }
  return {1e9,1e9};
}

pii solve(ll i, ll j){
  int lo = 0;
  int hi = 350;
  pii ans;
  while(lo <= hi){
    int mid = hi-(hi-lo)/2;
    pii tmp = valid(i, j, mid);
    if (tmp.first != 1e9) {
      ans = tmp;
      hi = mid-1;
    }
    else lo = mid+1;
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    track.insert({x[i],y[i]});
  }

  for (int i = 0; i < n; i++) {
    pii ans = solve(x[i], y[i]);
    cout << ans.first << " " << ans.second << endl;
  }

  
  return 0;
}
