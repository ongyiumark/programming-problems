#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 5000;
ll n;
ld fact[101];

ld solve(vector<ll> curr, int dep){
  ld total = 0;
  for (int i = 0; i < curr.size()-1; i++){
    total += (ld)(curr[i] + curr[i+1])/fact[n-dep-1];
    vector<ll> b = curr;
    b.erase(b.begin()+i, b.begin()+i+2);
    b.insert(b.begin()+i, curr[i] + curr[i+1]);
    total += solve(b, dep+1);
  }
  return total;
}

ld testcase() {
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  fact[n-1] = n-1;
  for (int i = n-2; i >= 1; i--){
    fact[i] = fact[i+1]*i;
  }
  return (ld)solve(a, 0);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  for (int x = 1; x <= t; x++){
    cout << "Case #" << x << ": ";
    cout << setprecision(10) << fixed << testcase() << "\n";
  }
  return 0;
}
