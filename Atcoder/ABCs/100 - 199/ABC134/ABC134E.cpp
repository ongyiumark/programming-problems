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

  int n; cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  vector<int> lis;
  for (int i = n-1; i >= 0; i--) {
    if (lis.size() == 0) lis.push_back(a[i]);
    else {
      auto it = upper_bound(lis.begin(), lis.end(), a[i]);
      if (it == lis.end()) lis.push_back(a[i]);
      else lis[it-lis.begin()] = a[i];
    }
  }  
  cout << lis.size() << "\n";
  
  return 0;
}
