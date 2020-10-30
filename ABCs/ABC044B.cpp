#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  map<char, int> cnt;
  string w;
  cin >> w;
  for (char c : w) cnt[c]++;

  bool valid = true;
  for (int i = 0; i < 26; i++){
    char c = i+'a';
    valid &= cnt[c]%2 == 0;
  }

  cout << (valid ? "Yes" : "No") << endl;
  return 0;
}
