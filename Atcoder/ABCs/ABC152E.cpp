/*
  Solve for LCM by prime factoring.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e4+1;
const int MOD = 1e9+7;

ll modpow(ll b, ll e){
  ll ans = 1;
  while(e > 0){
    if (e&1) ans = ans*b%MOD;
    b = b*b%MOD;
    e >>= 1;
  }
  return ans;
}

ll inv(int x){
  return modpow(x, MOD-2);
}

ll A[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];

  map<int, int> factors;
  for (int i = 0; i < n; i++){
    int j = 2;
    int temp = A[i];
    while(j*j <= temp){
      int cnt = 0;
      while(temp%j == 0){
        temp/=j;
        cnt++;
      }
      if (cnt > 0) factors[j] = max(factors[j], cnt);
      j++;
    }
    if (temp > 1) factors[temp] = max(factors[temp], 1);
  }

  ll lcm = 1;
  for (auto it : factors){
    lcm = lcm*modpow(it.first, it.second)%MOD;
  }

  ll ans = 0;
  for (int i = 0; i < n; i++){
    ans = (ans + lcm*inv(A[i])%MOD)%MOD;
  }
  cout << ans << endl;
  return 0;
}
