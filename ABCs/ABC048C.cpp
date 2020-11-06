#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5+1;
ll a[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, x; cin >> n >> x;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  ll ans = 0;
  for (int i = 1; i < n-1; i++){
    if (a[i] + a[i-1] > x) {
      ll need = a[i]+a[i-1]-x;
      ans += need;
      if (need <= a[i]){
        a[i] = a[i]-need;
      }
      else {
        need = need-a[i];
        a[i] = 0;
        a[i-1] = a[i-1]-need;
      }
    }
  }  

  if (a[n-2] + a[n-1] > x){
    ans += a[n-2]+a[n-1]-x;
  }

  cout << ans << endl;
  return 0;
}
