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

int n;
string s;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--) {
    cin >> n;
    cin >> s;

    ll total = 0;
    for (int l = 1; l <= 100; l++){
      for (int i = 0; i < n; i++) {
        vector<int> cnt(10,0);
        for (int j = 0; j < l; j++) {
          if (i+j >= n) break;
          cnt[s[i+j]-'0']++;
        }
        int distinct = 0;
        int hi = 0;
        for (int x = 0; x < 10; x++) {
          if (cnt[x] > 0) distinct +=1;
          hi = max(cnt[x], hi);
        }

        total += (hi > distinct);
      }
    }
    cout << total << endl;
  }
  
  return 0;
}
