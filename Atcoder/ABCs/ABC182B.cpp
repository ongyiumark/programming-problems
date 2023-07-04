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
  
  int n; cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;

  int best = 2;
  int best_cnt = 0;
  for (int k = 2; k <= 1000; k++) {
    int cnt = 0;
    for (int &x : a) {
      cnt += (x%k == 0);
    }

    if (best_cnt < cnt) {
      best_cnt = cnt;
      best = k;
    }
  }

  cout << best << "\n";
  return 0;
}
