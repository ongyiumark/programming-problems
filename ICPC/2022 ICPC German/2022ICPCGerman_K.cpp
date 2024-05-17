#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k; cin >> n >> k;
  string s; cin >> s;
  vector<int> known(n, -1);

  string steps = "LR";
  int cnt = 0;
  for (int i = 0; i < k; i++) {
    bool alive = true;
    int pos = 1;
    for (int j = 0; j < n; j++) {
      if (known[j] != -1) pos = known[j];
      else pos ^= 1;
      if (steps[pos] != s[j]) {
        alive = false;
        known[j] = pos^1;
        break;
      }
      known[j] = pos;
    }
    cnt += alive;
  }
  cout << cnt << "\n";

  return 0;
}