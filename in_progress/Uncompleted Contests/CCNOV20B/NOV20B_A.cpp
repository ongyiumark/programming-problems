#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    int c[n];
    for (int i = 0; i < n; i++){
      cin >> c[i];
    }
    sort(c, c+n);
    int ans = 1e9;
    do {
      int total = 0;
      for (int i = 0; i < n; i++){
        total += c[i];
      }
      int curr = 0;
      for (int i = 0; i < n; i++){
        curr += c[i];
        ans = min(ans, max(curr, total-curr));
      }
    } while(next_permutation(c, c+n));

    cout << ans << endl;
  }
  return 0;
}
