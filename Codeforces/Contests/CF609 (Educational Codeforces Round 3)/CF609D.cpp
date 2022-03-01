/*
  Fix the number of dollar gadgets and number of pound gadgets.
    This can be done by looping from 0 to k.
  For each of these, binary search from the minimum day that its possible to buy that
    specified number of dollar gadgets and pound gadgets.
  
  The objective function of the binary search can be done in O(1) with some precomputations.
*/
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
int a[N], b[N];
vector<pii> dollars, pounds;
vector<ll> cumdollars, cumpounds;
pii abest[N], bbest[N];
ll n, m, k, s; 

bool valid(int ndol, int npound, int day){
  ll need = 0;
  if (ndol > 0) need += cumdollars[ndol-1]*abest[day-1].second;
  if (npound > 0) need += cumpounds[npound-1]*bbest[day-1].second;
  return need <= s;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> k >> s;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < m; i++) {
    int t, c; cin >> t >> c;
    if (t == 1) dollars.push_back({c, i+1});
    else pounds.push_back({c,i+1});
  }

  sort(dollars.begin(), dollars.end());
  sort(pounds.begin(), pounds.end());

  for (pii d : dollars){
    ll tmp = d.first;
    if (cumdollars.size() > 0) tmp += cumdollars.back();
    cumdollars.push_back(tmp);
  }

  for (pii p : pounds){
    ll tmp = p.first;
    if (cumpounds.size() > 0) tmp += cumpounds.back();
    cumpounds.push_back(tmp);
  }

  pii bdollar = {-1,1e9};
  pii bpound = {-1,1e9};
  
  for (int i = 0; i < n; i++) {
    if (bdollar.second > a[i]) {
      bdollar = {i+1, a[i]};
    }
    if (bpound.second > b[i]) {
      bpound = {i+1, b[i]};
    }
    abest[i] = bdollar;
    bbest[i] = bpound;
  }

  int bans = 1e9;
  int besti = -1;
  for (int i = 0; i <= k; i++){
    if (i > dollars.size()) break;
    if (k-i > pounds.size()) continue;
    int lo = 1;
    int hi = n;
    int ans = -1;
    while (lo <= hi) {
      int mid = hi - (hi-lo)/2;
      if (valid(i, k-i, mid)) {
        ans = mid;
        hi = mid-1;
      }
      else lo = mid+1;
    }

    if (bans > ans && ans != -1) {
      bans = ans;
      besti = i;
    }
  }
  if (bans == 1e9) {
    cout << -1 << endl;
    return 0;
  }

  cout << bans << endl;
  for (int i = 0; i < besti; i++) {
    cout << dollars[i].second << " " << abest[bans-1].first << endl;
  }
  for (int i = 0; i < k-besti; i++) {
    cout << pounds[i].second << " " << bbest[bans-1].first << endl;
  }


  return 0;
}
