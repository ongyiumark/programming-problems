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

bool is_sorted(vector<int> &v) {
  int n = v.size();
  for (int i = 1; i < n; i++) {
    if (v[i] != v[i-1]+1) return false;
  }
  return true;
}
int main(){
  cin.tie(0)->sync_with_stdio(false);

  int n; cin >> n;
  vector<int> v(n);
  for (int &x : v) cin >> x;

  if (is_sorted(v)) {
    cout << "YES\n";
    return 0; 
  }
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      swap(v[i], v[j]);
      if (is_sorted(v)) {
        cout << "YES\n";
        return 0;
      }
      swap(v[i], v[j]);
    }
  }
  cout << "NO\n";
  
  return 0;
}
