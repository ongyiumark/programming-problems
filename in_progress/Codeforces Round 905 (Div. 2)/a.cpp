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
  while (t--) {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> cnt(26);
    for (char &ch : s) cnt[ch-'a']++;
    int cnt_odd = 0;
    for (int i = 0; i < 26; i++) {
      cnt_odd += (cnt[i]%2 == 1);
    }

    if (cnt_odd > 1) {
      if (cnt_odd-1 > k) {
        cout << "NO\n";
        continue;
      }
    }
    cout << "YES\n";
  }
  
  return 0;
}
