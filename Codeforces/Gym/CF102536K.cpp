/*
  Make a pair and sort.
*/
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

const int N = 1e5;
ll w[N], h[N];
pair<ll, ll> arr[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> w[i];
  for (int i = 0; i < n; i++) cin >> h[i];
  for (int i = 0; i < n; i++) arr[i] = {h[i], w[i]};
  sort(arr, arr+n);
  for (int i = 0; i < n; i++){
    cout << arr[i].second;
    cout << (i == n-1 ? "\n" : " ");
  }
  return 0;
}
