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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, s; cin >> n >> s;
  int tmpS = s;
  int res = 0;
  for (int i = 0; i < n; i++) {
    string t; cin >> t;
    int need = 0;
    if (t.size() == 2) need = t[0]-'0'+1;
    else need = t[0]-'0';

    if (need > tmpS) {
      tmpS = s;
      res++;
    }

    tmpS -= need;
  }

  cout << res << endl;
  
  return 0;
}
