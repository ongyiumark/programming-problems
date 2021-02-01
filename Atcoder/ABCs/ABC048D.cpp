/*
  If the first and last letters are the same, then the game ends when it is the same parity as there are 3 letters left.
  Otherwise, the game ends when it is the same parity as there are 2 letters left.
*/

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

  if (s[0] == s[n-1]){
    cout << ((n-3)%2 == 1 ? "First" : "Second") << endl;
  }
  else {
    cout << ((n-2)%2 == 1 ? "First" : "Second") << endl;
  }
  return 0;
}
