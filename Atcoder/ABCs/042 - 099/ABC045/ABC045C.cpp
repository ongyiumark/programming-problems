#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;
  int n = s.size();

  ll ans = 0;
  for (int i = 0; i < (1 << (n-1)); i++){
    ll total = 0;
    int left = 0;
    for (int j = 0; j < n-1; j++){
      if (i&(1 << j)) {
        total += stoll(s.substr(left, j-left+1));
        left = j+1;
      }
    }
    total += stoll(s.substr(left,n-left));
    ans += total;
  }

  cout << ans << endl;
  return 0;
}
