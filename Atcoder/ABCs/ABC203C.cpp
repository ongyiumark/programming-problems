/*
  Simulate it with coordinate compression.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<int,pair<int,int>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5+5;
pii arr[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll n, k; cin >> n >> k;
  for (int i = 0; i < n; i++) {
    ll a, b; cin >> a >> b;
    arr[i] = {a,b};
  }
  sort(arr, arr+n);

  int idx = 0;
  ll curr = 0;
  while(idx < n && curr+k >= arr[idx].first){
    k -= arr[idx].first-curr;
    curr = arr[idx].first;
    k += arr[idx].second;
    idx++;
  }
  cout << curr + k << endl;
  return 0;
}
