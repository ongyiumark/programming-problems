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

string A, B;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  cin >> A >> B;

  int m = 69;
  string ans = "";
  for (int i = 0; i < n; i+=m) {
    int lcs[m+1][m+1];
    memset(lcs, 0, sizeof lcs);
    for (int j = 1; j <= m; j++) {
      for (int k = 1; k <= m; k++) {
        if (i+j-1 >= n || i+k-1 >= n) continue; 
        if (A[i+j-1] == B[i+k-1]) lcs[j][k] = max({lcs[j-1][k-1]+1, lcs[j-1][k], lcs[j][k-1]});
        else lcs[j][k] = max({lcs[j-1][k-1], lcs[j-1][k], lcs[j][k-1]});
      }
    }

    int cj, ck;
    int best = 0;
    for (int j = 1; j <= m; j++) {
      for (int k = 1; k <= m; k++) {
        if (best < lcs[j][k]) {
          cj = j; ck = k;
          best = lcs[j][k];
        }
      }
    }

    string tmp = "";
    while(cj != 0 && ck != 0) {
      if (A[i+cj-1] == B[i+ck-1]) {
        tmp += A[i+cj-1];
        cj--; ck--;
      }
      else {
        if (lcs[cj-1][ck] >= lcs[cj][ck-1]) cj--;
        else ck--;
      }
    }
    reverse(tmp.begin(), tmp.end());
    ans += tmp;
  }
  cout << ans << endl;
  
  return 0;
}
