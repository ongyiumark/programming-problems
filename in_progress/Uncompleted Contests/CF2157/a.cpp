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
  cin.tie(0)->sync_with_stdio(false);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> freq(n+1);
    for (int i = 0; i < n; i++) {
      freq[a[i]]++;
    }

    int to_remove = 0;
    for (int i = 0; i <= n; i++) {
      if (freq[i] >= i) to_remove += freq[i]-i;
      else to_remove += freq[i];
    }

    cout << to_remove << "\n";

  }
  return 0;
}
