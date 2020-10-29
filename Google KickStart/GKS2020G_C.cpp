#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int W = 1e5;
ll x[W];
ll prefix[W];
ll w, n;

ll get_sum(int l, int r){
  if (l == 0) return prefix[r];
  return prefix[r]-prefix[l-1];
}

ll compute(ll i){
  int lo = 0; 
  int hi = i;

  int loc = -1;
  ll ans = 0;
  while(lo <= hi){
    int mid = hi - (hi-lo)/2;
    if (x[i]-x[mid] <= x[mid]-x[i]+n){
      loc = mid;
      hi = mid-1;
    }
    else lo = mid+1;
  }

  ans += get_sum(0, loc-1)-x[i]*loc + n*loc + (i-loc+1)*x[i]-get_sum(loc, i);

  lo = i+1;
  hi = w-1;
  loc = i;
  while(lo <= hi){
    int mid = hi - (hi-lo)/2;
    if (x[mid]-x[i] <= x[i]-x[mid]+n){
      loc = mid;
      lo = mid+1;
    }
    else hi = mid-1;
  }

  ans += get_sum(i+1, loc)-x[i]*(loc-i) + n*(w-1-loc) + x[i]*(w-1-loc) - get_sum(loc+1, w-1);
  return ans;
}

ll testcase() {
  cin >> w >> n;
  
  for (int i = 0; i < w; i++){
    cin >> x[i];
  }

  sort(x, x+w);

  prefix[0] = x[0];
  for (int i = 1; i < w; i++){
    prefix[i] = prefix[i-1]+x[i];
  }


  ll ans = 1e18;
  for (int i = 0; i < w; i++){
    ans = min(ans, compute(i));
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
