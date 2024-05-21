#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

string s;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s;
  int n = s.size();
  int ans = 0;
  for (int i = 1; i < n; i++){
    ans += s[i-1] != s[i];
  }

  cout << ans << endl;
  return 0;
}
