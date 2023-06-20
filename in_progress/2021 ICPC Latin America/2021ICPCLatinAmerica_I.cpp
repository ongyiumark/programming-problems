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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  map<string, int> day_no;
  vector<string> days = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
  for (int i = 0; i < 7; i++) day_no[days[i]] = i;

  string T; cin >> T;
  int n; cin >> n;
  int T_no = day_no[T];

  vector<int> D(n);
  vector<int> res(n);
  for (int i = 0; i < n; i++) {
    cin >> D[i];

    int D_no = (T_no - D[i])%7;
    if (D_no < 0) D_no += 7;
    int renew = -D[i];

    if (D[i] == 0) {
      // deposited today
      D_no = (D_no + 30)%7;
      renew += 30;

      // add days if weekend
      if (D_no >= 5) {
        renew += 7-D_no;
        D_no = 0;
      }
      
      res[i] = renew;
      continue;
    }

    // continue until monday
    while(renew < 0 && D_no != 0) {
      D_no = (D_no + 30)%7;
      renew += 30;
      if (D_no >= 5) {
        renew += 7-D_no;
        D_no = 0;
      }
    }
    renew %= 91;
    while(renew < 0) {
      D_no = (D_no + 30)%7;
      renew += 30;
      if (D_no >= 5) {
        renew += 7-D_no;
        D_no = 0;
      }
    }

    res[i] = renew;
  }

  int ans = 1000;  
  for (int i = 0; i < n; i++) ans = min(ans, res[i]);
  cout << ans << "\n";
  return 0;
}
