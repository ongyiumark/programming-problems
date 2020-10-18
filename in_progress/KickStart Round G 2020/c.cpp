#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int W = 1e5;
ll x[W];
ll w, n;
map<int, ll> memo;

ll compute(ll y){
  ll ans = 0;
  for (int i = 0; i < w; i++){
    ll a = max(y, x[i]);
    ll b = min(y, x[i]);
    ans += min(a-b,b+(n-a));
  }
  return ans;
}

ll testcase() {
  cin >> w >> n;

  for (int i = 0; i < w; i++){
    cin >> x[i];
  }

  sort(x, x+w);

  ll ans = 1e18;

  int lo = 0;
  int hi = w-1;
  int peak = -1;
  while(lo <= hi){
    int mid = hi - (hi-lo)/2;
    if (compute(x[mid]) < compute(x[(mid+1)%w])){
      lo = mid+1;
    }
    else if (compute(x[mid]) < compute(x[(mid-1+w)%w])){
      hi = mid-1;
    }
    else {
      peak = mid;
      break;
    }
  }

  if (peak == -1){
    lo = 0;
    hi = w-1;
    while(lo <= hi){
      int mid = hi - (hi-lo)/2;
      ll a = compute(x[(mid-1+w)%w]);
      ll b = compute(x[mid]);
      ll c = compute(x[(mid+1)%w]);
      ans = min({ans, a, b, c});
      if (b > c){
        lo = mid+1;
      }
      else if (b > a){
        hi = mid-1;
      }
      else {
        break;
      }
    }
  }
  else {
    lo = 0;
    hi = peak;
    while(lo <= hi){
      int mid = hi - (hi-lo)/2;
      ll a = compute(x[(mid-1+w)%w]);
      ll b = compute(x[mid]);
      ll c = compute(x[(mid+1)%w]);
      ans = min({ans, a, b, c});
      if (b > c){
        lo = mid+1;
      }
      else if (b > a){
        hi = mid-1;
      }
      else {
        break;
      }
    }

    lo = peak;
    hi = w-1;
    while(lo <= hi){
      int mid = hi - (hi-lo)/2;
      ll a = compute(x[(mid-1+w)%w]);
      ll b = compute(x[mid]);
      ll c = compute(x[(mid+1)%w]);
      ans = min({ans, a, b, c});
      if (b > c){
        lo = mid+1;
      }
      else if (b > a){
        hi = mid-1;
      }
      else {
        break;
      }
    }
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  for (int x = 1; x <= t; x++){
    cout << "Case #" << x << ": ";
    cout << testcase() << "\n";
  }
  return 0;
}
