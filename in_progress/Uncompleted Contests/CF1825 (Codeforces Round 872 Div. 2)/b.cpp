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

void testcase() {
  ll n, m; cin >> n >> m;
  vector<ll> b(n*m);
  for (int i = 0; i < n*m; i++) cin >> b[i];
  sort(b.begin(), b.end());


  ll hi1 = b[n*m-1];
  ll hi2 = b[n*m-2];
  ll lo1 = b[0];
  ll lo2 = b[1];

  ll ans1 = (hi1-lo1)*(n-1)*m + (hi1-lo2)*(m-1);
  swap(n, m);
  ll ans2 = (hi1-lo1)*(n-1)*m + (hi1-lo2)*(m-1);
  swap(n, m);

  ll ans3 = (hi1-lo1)*(n-1)*m + (hi2-lo1)*(m-1);
  swap(n, m);
  ll ans4 = (hi1-lo1)*(n-1)*m + (hi2-lo1)*(m-1);
  swap(n, m);

  cout << max({ans1, ans2, ans3, ans4}) << "\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while(t--) {
    testcase();
  }
  return 0;
}
