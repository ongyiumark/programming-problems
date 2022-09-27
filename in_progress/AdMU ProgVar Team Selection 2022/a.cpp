#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e3+5;
char grid[N][N];
int J[N][N], O[N][N], I[N][N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int m, n; cin >> m >> n;
  int k; cin >> k;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
      J[i][j] = O[i][j] = I[i][j];
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      J[i][j] += (grid[i][j] == 'J');
      O[i][j] += (grid[i][j] == 'O');
      I[i][j] += (grid[i][j] == 'I');
      if (i == 0 && j == 0) continue;
      if (i == 0) {
        J[i][j] += J[i][j-1];
        O[i][j] += O[i][j-1];
        I[i][j] += I[i][j-1];
      }
      else if (j == 0) {
        J[i][j] += J[i-1][j];
        O[i][j] += O[i-1][j];
        I[i][j] += I[i-1][j];
      }
      else {
        J[i][j] += J[i-1][j]+J[i][j-1]-J[i-1][j-1];
        O[i][j] += O[i-1][j]+O[i][j-1]-O[i-1][j-1];
        I[i][j] += I[i-1][j]+I[i][j-1]-I[i-1][j-1];
      }
    }
  }

  for (int x = 0; x < k; x++) {
    int a, b, c, d; cin >> a >> b >> c >> d;
    a--; b--; c--; d--;
    
    int Jans = J[c][d];
    int Oans = O[c][d];
    int Ians = I[c][d];

    if (a > 0) {
      Jans -= J[a-1][d];
      Oans -= O[a-1][d];
      Ians -= I[a-1][d];
    }
    if (b > 0) {
      Jans -= J[c][b-1];
      Oans -= O[c][b-1];
      Ians -= I[c][b-1];
    }

    if (a > 0 && b > 0) {
      Jans += J[a-1][b-1];
      Oans += O[a-1][b-1];
      Ians += I[a-1][b-1];
    }

    cout << Jans << " " << Oans << " " << Ians << "\n";
  }

  return 0;
}
