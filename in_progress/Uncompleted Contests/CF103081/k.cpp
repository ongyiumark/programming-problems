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

string s;
int n;
const ll M = 1e9+7;

ll modpow(ll b, ll e, ll m){
  ll ans = 1;
  while(e > 0){
    if (e&1) ans = (ans*b)%m;
    e >>= 1;
    b = (b*b)%m;
  }
  return ans;
}

ll modinv(ll x, ll p){
  return modpow(x, p-2, p);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int randint(int l, int r) { return uniform_int_distribution<int>(l,r)(rng); }

ll base, baseinv;

pair<bool, int> valid(int len){
  ll myhash = 0;
  ll p = 1;
  for (int i = 0; i < len; i++){
    if (i > 0) p = p*base%M;

    myhash = (myhash + (s[i]-'A')*p)%M;
  }

  map<ll, int> tracker;
  tracker[myhash] = 0;
  for (int i = len; i < n; i++){

    // Subtract previous character
    myhash -= (s[i-len]-'A');
    myhash %= M;

    if (myhash < 0) myhash += M;

    // Divide by base
    myhash = myhash*baseinv%M;

    // Add next character
    myhash = (myhash + (s[i]-'A')*p)%M;

    if (tracker.find(myhash) != tracker.end()) {
      tracker[myhash] = -1;
    }
    else tracker[myhash] = i-len+1;
  }

  int idx = n;
  for (auto it : tracker){
    if (it.second >= 0) idx = min(idx, it.second);
  }
  
  if (idx == n) {
    return {false, -1};
  }

  return {true, idx};
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> s;
  n = s.size();

  base = randint(26, 100);
  baseinv = modinv(base, M);

  int lo = 1;
  int hi = n;
  pair<int,int> ans;
  while(lo <= hi) {
    int mid = hi - (hi-lo)/2;
    pair<bool, int> res = valid(mid);
    if (res.first){
      ans = {res.second, mid};
      hi = mid-1;
    }
    else lo = mid+1;
  }

  cout << s.substr(ans.first, ans.second) << endl;
  return 0;
}
