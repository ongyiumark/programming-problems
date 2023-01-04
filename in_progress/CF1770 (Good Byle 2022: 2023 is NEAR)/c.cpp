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


  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    ll a[n];

    int m = 105;
    ll mods[m][m];
    memset(mods, 0, sizeof mods);

    unordered_map<ll, int> freq;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      
      for (int j = 2; j < m; j++) {
        mods[j][a[i]%j]++;
      }

      freq[a[i]]++;
    }

    bool val = 1;
    for (int j = 2; j < m; j++) {
      bool tmp = 1;
      for (int k = 0; k < j; k++) {
        tmp &= (mods[j][k] >= 2);
      }
      if (tmp) val = 0;
    }

    for (auto it : freq) {
      if (it.second > 1) {
        val = 0;
      }
    }

    if (!val) {
      cout << "No\n";
      continue;
    }

    cout << "Yes\n";
  }
  
  return 0;
}
