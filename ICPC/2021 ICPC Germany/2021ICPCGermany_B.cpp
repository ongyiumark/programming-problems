#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

bool is_vowel(char ch) {
  for (char vowel : {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}) {
    if (ch == vowel) return true;
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s; cin >> s;
  int n = s.size();

  int last_vowel = -1;
  for (int i = 0; i < n; i++) {
    if (is_vowel(s[i])) last_vowel = i;
  }
  cout << s.substr(0, last_vowel+1) << "ntry\n";

  
  return 0;
}