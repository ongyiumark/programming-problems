#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll parse(char c) {
  if ('2' <= c && c <= '9') return c-'0';
  if (c == 'A') return 1;
  return 10;
}

ll parse2(char c) {
  if ('2' <= c && c <= '9') return c-'0';
  if (c == 'A') return 1;
  if (c == 'T') return 10;
  if (c == 'J') return 11;
  if (c == 'Q') return 12;
  return 13;
}

ll fifteens(vector<char> &ar) {
  int n = ar.size();
  vector<ll> vals(n);
  for (int i = 0; i < n; i++) vals[i] = parse(ar[i]);

  vector<ll> ways(16);
  ways[0] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 15; j >= 0; j--)
      if (j-vals[i] >= 0)
        ways[j] += ways[j-vals[i]];
  
  return 2*ways[15];
}

ll pairs(vector<char> &ar) {
  map<char, ll> freq;
  for (int c : ar) freq[c]++;

  ll total = 0;
  for (auto [key, val] : freq) total += val*(val-1);
  return total;
}

ll runs(vector<char> &ar) {
  int n = ar.size();
  vector<ll> vals(n);
  for (int i = 0; i < n; i++) vals[i] = parse2(ar[i]);

  map<int,ll> freq;
  for (int x : vals) freq[x]++;
  ll l = 1, r = 1;

  ll total = 0;
  while (l <= 13) {
    if (freq[l] == 0) l++, r++;
    else if (r <= 13 && freq[r] > 0) r++;
    else {
      if (r-l >= 3) {
        ll prod = 1;
        for (int i = l; i < r; i++) prod *= freq[i];
        
        total += prod*(r-l);
      }
      l = r;
    }
  }

  return total;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<char> ar(n);
  for (int i = 0; i < n; i++) cin >> ar[i];

  cout << fifteens(ar) + pairs(ar) + runs(ar) << "\n";

  return 0;
}