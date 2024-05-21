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
  vector<int> p(n);
  for (auto &x : p) cin >> x;

  int cnt = 0;
  for (int i = 1; i < n-1; i++) {
    cnt += (p[i] == max({min(p[i-1], p[i]), min(p[i], p[i+1]), min(p[i-1], p[i+1])}));
  }

  cout << cnt << "\n"; 

  return 0;
}
