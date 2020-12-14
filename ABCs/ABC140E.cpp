#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int N = 1e5+1;

ordered_set<ll> myset;

pair<ll,ll> arr[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  int n; cin >> n;
  for (int i = 0; i < n; i++){
    ll p; cin >> p;
    arr[i] = {p, i};
  }

  sort(arr, arr+n, greater<pair<ll, ll>>());

  ll ans = 0;
  for (int i = 0; i < n; i++){
    ll x = myset.order_of_key(arr[i].second);
    ll a, b, c, d;
    a = b = -1;
    c = d = n;
    
    if (x-1 >= 0) b = *myset.find_by_order(x-1);
    if (x-2 >= 0) a = *myset.find_by_order(x-2);
    if (x < myset.size()) c = *myset.find_by_order(x);
    if (x+1 < myset.size()) d = *myset.find_by_order(x+1);

    myset.insert(arr[i].second);

    ans += arr[i].first * ((b-a)*(c-arr[i].second) + (arr[i].second - b)*(d-c));
  }
  
  cout << ans << endl;
  return 0;
}
