/*
  Just greedily buy from the cheapest store.
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

const int N = 1e5+5;
pair<ll, int> store[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> store[i].first >> store[i].second;
  sort(store, store+n);

  ll total = 0;
  for (int i = 0; i < n && m > 0; i++){
    total += min(m, store[i].second)*store[i].first;
    m -= store[i].second;
  }
  cout << total << endl;
  return 0;
}
