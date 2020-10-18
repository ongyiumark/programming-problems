#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1005;
ll c[N][N];
ll diag[2*N];

ll testcase() {
  int n; cin >> n;
  memset(diag, 0, sizeof diag);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> c[i][j];
      diag[i-j+n] += c[i][j];
    }
  }
  ll ans = 0;
  for (int i = 1; i < 2*n; i++){
    ans = max(ans, diag[i]);
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
