#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++){
    int x; cin >> x;
    ans += x != 1;
  }
  cout << ans << endl;
  return 0;
}
