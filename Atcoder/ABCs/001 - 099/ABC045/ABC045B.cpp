#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s[3];
  for (int i = 0; i < 3; i++) cin >> s[i];

  int idx[3];
  memset(idx, 0, sizeof idx);

  int curr = 0;
  while(idx[curr] < (int)s[curr].size()){
    idx[curr]++;
    curr = s[curr][idx[curr]-1]-'a';
  }

  cout << (char)(curr+'A') << endl;
  return 0;
}
