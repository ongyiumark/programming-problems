#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, l; cin >> n >> l;
  string s[n];
  for (int i = 0; i < n; i++){
    cin >> s[i];
  }

  sort(s, s+n);
  for (int i = 0; i < n; i++){
    cout << s[i];
  }
  cout << endl;
  return 0;
}
