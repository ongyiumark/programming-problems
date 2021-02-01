/*
  Sort by a and add up the b's until they reach k.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5;
pair<ll,ll> arr[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, k; cin >> n >> k;

  for (int i = 0; i < n; i++){
    int a, b; cin >> a >> b;
    arr[i] = {a,b};
  }
  sort(arr, arr+n);

  ll total = 0;
  int i = 0;
  while(total < k){
    total += arr[i].second;
    i++;
  }
  cout << arr[i-1].first << endl;
  return 0;
}
