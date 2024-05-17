#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool ended(int n, int a, int b) {
  if (a < 0 || b < 0) return true; 

  if (a > n && b > n) return abs(a-b) == 2;
  if (a > n) return b == a-2;
  if (b > n) return a == b-2;
  if (a == n) return b <= a-2;
  if (b == n) return a <= b-2;

  return false;
}
int main(){
  cin.tie(0)->sync_with_stdio(false);

  int t; cin >> t;
  while (t--) {
    int n, a, b; cin >> n >> a >> b;
    vector<vector<ll>> memo(a+1, vector<ll>(b+1, -1));
    function<ll(int,int)> solve = [&](int x, int y) -> ll {
      if (x < 0 || y < 0) return 0;
      ll &ans = memo[x][y];
      if (ans != -1) return ans;
      if (x == 0 && y == 0) return ans = 1;
      ans = 0;
      if (!ended(n, x-1, y)) ans += solve(x-1, y);
      if (!ended(n, x, y-1)) ans += solve(x, y-1);
      return ans;
    };

    if (ended(n, a, b)) cout << solve(a, b) << "\n";
    else cout << 0 << "\n";
  }
  return 0;
}