#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

string s, c;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s >> c;
  int n = s.size();
  int m = c.size();

  int ans = 0;
  for (int i = 0; i < n-m+1; i++){
    bool valid = true;
    for (int j = 0; j < m; j++){
      if (s[i+j] == c[j]) valid = false;
    }
    ans += valid;
  }
  cout << ans << endl;
  return 0;
}
