#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int solve(string &s, string &t) {
  vector<int> idx(255);
  for (int i = 0; i < 4; i++) idx[t[i]] = i;

  int n = s.size();
  vector<int> as_num(n);
  for (int i = 0; i < n; i++) as_num[i] = idx[s[i]];

  vector<int> lis; lis.push_back(as_num[0]);
  for (int i = 1; i < n; i++) {
    int lo = 0;
    int hi = lis.size()-1;
    int ans = -1;
    while (lo <= hi) {
      int mid = hi-(hi-lo)/2;
      if (lis[mid] > as_num[i]) {
        ans = mid;
        hi = mid-1;
      }
      else lo = mid+1;
    }
    if (ans == -1) lis.push_back(as_num[i]);
    else lis[ans] = as_num[i];
  }

  return n-lis.size();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s; cin >> s;
  string t = "cdhs";

  int res = 1e9;
  do {
    res = min(res, solve(s,t));
  } while (next_permutation(t.begin(), t.end()));
  cout << res << "\n";
  return 0;
}