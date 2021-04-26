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

ll modpow(ll b, ll e, ll m){
  ll ans = 1;
  while(e > 0){
    if (e&1) ans = (__int128)ans*b%m;
    b = (__int128)b*b%m;
    e >>= 1;
  }
  return ans;
}

const ll mod = 1e9*60LL*60LL*12LL;
ll modinv(ll x){
  return modpow(x, 11520000000000LL-1, mod);
}

bool valid(ll a, ll b, ll c){
  return (12*a%mod == b && 720*a%mod == c);
}

// 1, 12, 720
void testcase(){
  ll t[3];
  for (int i = 0; i < 3; i++){
    cin >> t[i];
  }
  sort(t, t+3);
  do{
    ll a = t[0], b = t[1], c = t[2];
    ll mintemp = (12*a%mod-b)%mod;
    ll sectemp = (720*a%mod-c)%mod;
    if (mintemp < 0) mintemp+=mod;
    if (sectemp < 0) sectemp+=mod;
    // mintemp + 11d (mod) = 0
    // sectemp + 719d (mod) = 0

    if (719*mintemp%mod != 11*sectemp%mod) continue;
    
    ll x = 719*mintemp%mod;
    ll d = (__int128)x*modinv(mod-11*719)%mod;
    
    if (!valid((a+d+mod)%mod,(b+d+mod)%mod,(c+d+mod)%mod)) continue;
    ll nsecs = (a+d+mod)%mod;
    //cout << nsecs << " " << d << endl;
    ll hourmod = 1e9*60LL*60LL;
    ll h = nsecs/hourmod;
    nsecs%=hourmod;

    ll minmod = 1e9*60LL;
    ll m = nsecs/minmod;
    nsecs%=minmod;

    ll secmod = 1e9;
    ll s = nsecs/secmod;
    nsecs%=secmod;

    cout << h << " " << m << " " << s << " " << nsecs << endl;
    return;
  } while(next_permutation(t, t+3));
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  for (int x = 1; x <= t; x++){
    cout << "Case #" << x << ": ";
    testcase();
  }
  return 0;
}
