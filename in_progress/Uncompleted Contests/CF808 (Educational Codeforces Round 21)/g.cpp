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

const int N = 2e5+5;
int p[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s, t; cin >> s >> t;
  int n = s.size();
  int m = t.size();

  string st = t+"#"+s;

  vector<vector<int>> dp(n,vector<int>(m,-1));

  // Build prefix
  int L = 0;
  p[0] = 0;
  dp[0][p[0]] = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 0; i < m; j++) {
      dp[i][j] = dp[i-1][j];
    }

    if (st[L] == '?' && st[i] == '?') {

    }
    else if (st[L] == '?') {

    }
    else if (st[i] == '?') {

    }
    else {
      if (st[L] == st[i]) {
        p[i] = L+1;
        L++;
      }
      else if (L > 0 && st[L-1] == st[i-1]) {
        L = p[L-1];
      }
      else p[i] = 0;
    }
  }

  cout << st << endl;
  for (int i = 0; i < n; i++) {
    cout << p[i] << " ";
  }
  cout << endl;
  
  return 0;
}
