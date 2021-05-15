#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll n, k;
void testcase(){
  cin >> n >> k;
  ll P[n];
  for (int i = 0; i < n; i++){
    cin >> P[i];
  }
  sort(P, P+n);
  ll ans = P[0]-1+k-P[n-1];
  vector<ll> diff;
  for (int i = 1; i < n; i++){
    ans = max(ans, P[i]-P[i-1]-1);
    diff.push_back(P[i]-P[i-1]);
  }

  for (int i = 1; i < n; i++){
    if (P[i]==P[i-1]) continue;
    ans = max(ans, max(P[0]-1, k-P[n-1])+(P[i]-P[i-1])/2);
  }

  sort(diff.begin(), diff.end(), greater<ll>());
  if (diff.size() > 1) ans = max(diff[0]/2+ diff[1]/2, ans);

  cout << setprecision(10) << fixed;
  cout << (ld)ans/k << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  for (int x = 1; x <= t; x++){
    cout << "Case #" << x << ": ";
    testcase();
  }
  return 0;
}
