#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

struct Card {
  char r, s;
  Card(const string &c) : r(c[0]), s(c[1]) {}
  bool same_rank(const Card &other) { return r == other.r; }
  bool same_suit(const Card &other) { return s == other.s; }
  string to_string() const {
    ostringstream os;
    os << r << s;
    return os.str();
  }
};

bool process(vector<Card> &ar) {
  int n = ar.size();
  vector<Card> res;

  vector<bool> to_remove(n, 0);
  for (int i = n-1; i-3 >= 0; i--) {
    if (!ar[i].same_rank(ar[i-3])) continue;

    for (int j = i-3; j <= i; j++) to_remove[j] = 1;
    break;
  }

  for (int i = 0; i < n; i++)
    if (!to_remove[i])
      res.push_back(ar[i]);
  if (res.size() < n) {
    ar = res;
    return true;
  }

  res.clear();
  for (int i = n-1; i-3 >= 0; i--) {
    if (!ar[i].same_suit(ar[i-3])) continue;
    to_remove[i] = 1;
    to_remove[i-3] = 1;
    break;
  }

  for (int i = 0; i < n; i++)
    if (!to_remove[i])
      res.push_back(ar[i]);
  if (res.size() < n) {
    ar = res;
    return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<Card> ar;
  for (int i = 0; i < 52; i++) {
    string s; cin >> s;
    ar.push_back(Card(s));
  }

  vector<Card> current;
  for (Card c : ar) {
    current.push_back(c);
    while(process(current));
  }
  int n = current.size();
  cout << n;
  for (Card c : current) {
    cout << " " << c.to_string();
  }  
  cout << "\n";


  return 0;
}