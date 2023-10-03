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

const int N = 1e5+5;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  vector<int> d(n);
  for (int &x : d) cin >> x;
  sort(d.begin(), d.end());

  int idx = 0;
  int cnt = 0;
  for (int k = 0; k < N; k++) {
    while (idx < n && d[idx] < k) idx++;
    if (2*idx == n) cnt++;
  }

  cout << cnt << "\n";
  
  return 0;
}
