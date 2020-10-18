#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

string a = "KICK";
string b = "START";
int testcase() {
  string s; cin >> s;
  int n = s.size();
  int kick_count = 0;
  int ans = 0;
  for (int i = 0; i < n; i++){
    if (i + a.size() <= n){
      kick_count += (a == s.substr(i, a.size()));
    } 
    if (i + b.size() <= n){
      if (b == s.substr(i, b.size())){
        ans += kick_count;
      }
    }
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
