#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<char> ans;
  string s;
  cin >> s;
  for (char c : s){
    if (c != 'B') ans.push_back(c);
    else {
      if (ans.size() > 0) ans.pop_back();
    }
  }

  for (char c : ans) cout << c;
  cout << endl;
  return 0;
}
