/*
  Firstly, we can divide everything by 100 to make it easier to work with.

  Notice that if we don't unlock the bonuses, it's always better to solve the problems with higher points.
  So, every set of problems must either be completely solved or not at all.
  The only set of problems that is solved halway is the set with the highest points that has not yet been completely solved.

  Thus, we only need to try 2^10 possibilities.
*/
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

int p[11], c[11];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int d, g; cin >> d >> g;
  g /= 100;
  for (int i = 1; i <= d; i++){
    cin >> p[i] >> c[i];
    c[i] /= 100;
  }

  int ans = 1e9;
  for (int i = 0; i < (1<<10); i++){
    int score = 0;
    int probs = 0;
    for (int j = 0; j < 10; j++){
      int x = j+1;
      if (i&(1<<j)) {
        score += x*p[x] + c[x];
        probs += p[x];
      }
    }
    for (int j = 9; j >= 0 && g > score; j--){
      if (i&(1<<j)) continue;
      int x = j+1;
      int need = (g-score+x-1)/x;
      if (need < p[x]) {
        probs += need;
        score += x*need;
      }
      break;
    }
    if (score >= g) ans = min(ans, probs);
  }
  cout << ans << endl;
  return 0;
}
