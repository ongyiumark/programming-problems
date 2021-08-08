/*
  It takes 50 moves to turn 1-50 into 0-49.
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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll k; cin >> k;

  int n = 50;
  vector<ll> ans(n);
  ll d = k/50;
  ll r = k%50;

  iota(ans.begin(), ans.end(), 0);
  for (int i = 0; i < n; i++){
    ans[i] += d;
  }
  for (int i = 1; i <= r; i++){
    ans[n-i]++;
  }

  cout << n << endl;
  for (int i = 0; i < n; i++){
    cout << ans[i];
    cout << (i == n-1 ? "\n" : " ");
  }
  return 0;
}
