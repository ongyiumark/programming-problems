#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int c, n; cin >> c >> n;
  vector<int> ar(n);
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }

  vector dp(2, vector(c+1, vector(c+1, false)));
  vector<vector<bool>> &prevdp = dp[0];
  vector<vector<bool>> &nextdp = dp[1];

  prevdp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int a = c; a >= 0; a--) {
      for (int b = c; b >= 0; b--) {
        nextdp[a][b] = prevdp[a][b];

        if ((a-ar[i] < 0) && (b-ar[i] < 0)) continue;
        else if (a-ar[i] < 0) nextdp[a][b] = (nextdp[a][b]|prevdp[a][b-ar[i]]);
        else if (b-ar[i] < 0) nextdp[a][b] = (nextdp[a][b]|prevdp[a-ar[i]][b]);
        else nextdp[a][b] = (nextdp[a][b] | prevdp[a-ar[i]][b] | prevdp[a][b-ar[i]]);
      }
    }
    swap(prevdp, nextdp);
  }

  int best = -1, best_a, best_b;
  for (int a = 0; a <= c; a++) {
    for (int b = 0; b <= a; b++) {
      if (!prevdp[a][b]) continue;
      if (best < a+b) {
        best = a+b;
        best_a = a;
        best_b = b;
      }
      if (best == a+b && best_a-best_b > a-b) {
        best_a = a;
        best_b = b;
      } 
    }
  }

  cout << best_a << " " << best_b << "\n";
  
  return 0;
}