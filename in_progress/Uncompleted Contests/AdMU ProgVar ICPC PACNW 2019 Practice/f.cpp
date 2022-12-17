#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int DMAX = 21;
ll d[DMAX];

const int CMAX = 51;
ll comb[CMAX][CMAX];

void compute_catalan() {
  memset(d, 0, sizeof d);
  d[0] = 1; d[1] = 0;
  for (int i = 2; i < DMAX; i++) {
    d[i] = (i-1)*(d[i-1]+d[i-2]);
  }
}

void compute_comb() {
  memset(comb, 0, sizeof comb);
  for (int i = 0; i < CMAX; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0) comb[i][j] = 1;
      else comb[i][j] = comb[i-1][j-1]+comb[i-1][j];
    }
  }
}

bool enough(int n, int m, int k) {
  if (n < m) return false;
  if (n-m == 1) return true;
  if (n-m >= DMAX) return true;
  if (comb[n][m] == 1) {
    return k < d[n-m];
  }
  if (k <= d[n-m]) return true;
  if (comb[n][m] > k/d[n-m]) return true;
  if (comb[n][n] == k/d[n-m] && k%d[n-m] == 0) return true;
  return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll n, m, k;
  cin >> n >> m >> k;
  compute_catalan();
  compute_comb();

  // If m = n-1, then the last number must also be fixed;
  if (n-m == 1) {
    cout << -1 << endl;
    return 0;
  }

  vector<int> ans(n+1, 0);
  ordered_set<int> os;
  for (int i = 1; i <= n; i++) {
    os.insert(i);
  }

  int mleft = m;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < (int)os.size(); j++) {
      bool found = false;
      int curr = *os.find_by_order(j);
      //cout << i << " " << curr << endl;
      if (curr != i) {
        if (!enough(n-i, mleft, k)) {
          if (n-i-mleft < 0) {
            continue;
          }
          //cout << "   " << comb[n-i][mleft] << " " << d[n-i-mleft] << " " << k << endl;
          k -= comb[n-i][mleft]*d[n-i-mleft];
          continue;
        }
        // not fix
        ans[i] = curr;
        found = true;
      }
      else {
        if (!enough(n-1, mleft-1, k)) {
          if (n-i-mleft-1 < 0) {
            continue;
          }
          //cout << "   " << comb[n-i][mleft-1] << " " << d[n-i-mleft-1] << " " << k << endl;
          k -= comb[n-i][mleft-1]*d[n-i-mleft-1];
          continue;
        }
        // fix
        mleft -= 1;
        ans[i] = curr;
        found = true;
      }

      if (found) {
        os.erase(os.find_by_order(j));
        break;
      }
      else if (j+1 == (int)os.size()) {
        cout << -1 << endl;
        return 0;
      }
    }
  }

  if (k > 0 || mleft > 0) {
    cout << -1 << endl;
    cout << k << "  " << mleft << endl;
    return 0;
  }

  for (int i = 1; i <=n ; i++) {
    cout << ans[i];
    if (i == n) cout << endl;
    else cout << " ";
  }


  return 0;
}
