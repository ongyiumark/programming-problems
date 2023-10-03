#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

vector<int> query(string s) {
  cout << "? " << s << endl;
  int n; cin >> n;
  vector<int> res(n);
  for (int &x : res) cin >> x;
  return res;
}

string guess(string s) {
  cout << "! " << s << endl;
  string res; cin >> res;
  return res;
}

const int N = 1e4+5;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // get length
  string s = "";
  for (char ch = 'a'; ch <= 'z'; ch++) s += ch;
  vector<int> res = query(s);
  int n = res.size();
  string ans(n, ' ');

  vector<string> query_strings(5);
  for (int i = 1; i <= 26; i++) {
    for (int j = 0; j < 5; j++) {
      if ((i>>j)&1) query_strings[j] += 'a'+i-1;
    }
  }

  vector<bitset<N>> results(5);
  for (int i = 0; i < 5; i++) {
    vector<int> tmp = query(query_strings[i]);
    for (int x : tmp) results[i].set(x);
  }

  for (int i = 1; i <= 26; i++) {
    bitset<N> s;
    s = (~s);
    for (int j = 0; j < 5; j++) {
      if ((i>>j)&1) s &= results[j];
      else s &= (~results[j]);
    }

    for (int j = 1; j <= n; j++) {
      if (s[j]) ans[j-1] = 'a'+i-1;
    }
  }
  cout << "! " << ans << endl; 
  

  return 0;
}