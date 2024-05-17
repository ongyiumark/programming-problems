#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int d, k; cin >> d >> k;
  vector<int> digits(d);
  for (int &x : digits) cin >> x;
  sort(digits.rbegin(), digits.rend());

  vector<int> pow10(d);
  pow10[0] = 1;
  for (int i = 1; i < d; i++) pow10[i] = pow10[i-1]*10%k;


  vector<bool> seen(1<<d);
  vector<vector<bool>> memo(1<<d, vector<bool>(k, 0));
  function<vector<bool>(int)> solve = [&](int mask) {
    if (seen[mask]) return memo[mask];
    seen[mask] = 1;
    vector<bool> &ans = memo[mask];
    if (mask == (1<<d)-1) {
      ans[0] = 1;
      return ans;
    }
    int cnt = d-__builtin_popcount(mask);
    for (int i = 0; i < d; i++){
      if ((mask>>i)&1) continue;
      auto tmp = solve(mask|(1<<i));
      
      for (int j = 0; j < k; j++) {
        if (!tmp[j]) continue;
        int nj = (j+digits[i]*pow10[cnt-1])%k;
        ans[nj] = true;
      }
    }
    return ans;
  };

  vector<int> result;
  auto possible = solve(0);
  int largest = k-1;
  for (; !possible[largest]; largest--);

  int mask = 0;
  for (int x = 0; x < d; x++) {
    for (int i = 0; i < d; i++) {
      if ((mask>>i)&1) continue;
      auto tmp = solve(mask^(1<<i));

      int target = (largest-digits[i]*pow10[d-x-1])%k;
      if (target < 0) target += k;
      if (tmp[target]) {
        mask ^= (1<<i);
        result.push_back(digits[i]);
        largest = target;
        break;
      }
    }
  }
  for (int &x : result) cout << x;
  cout << "\n";

  return false;
}