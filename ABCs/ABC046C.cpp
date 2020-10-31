#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1001;
ll t[N];
ll a[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  for (int i = 0; i < n; i++){
    cin >> t[i] >> a[i];
  }

  ll T = t[0];
  ll A = a[0];
  for (int i = 1; i < n; i++){
    ll nt = (T+t[i]-1)/t[i];
    ll na = (A+a[i]-1)/a[i];
    T = t[i]*max(na, nt);
    A = a[i]*max(na, nt);
  }

  cout << T+A << endl;
  return 0;
}
