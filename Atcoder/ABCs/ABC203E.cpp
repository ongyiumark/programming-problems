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

const int MAXM = 2e5+5;
map<ll, vector<ll>> blacks;
set<ll> s1;
ll X[MAXM], Y[MAXM];

set<ll> xs;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    ll x, y; cin >> x >> y;
    blacks[x].push_back(y);
    xs.insert(x);
  } 

  s1.insert(n);
  for (auto x : xs) {
    set<ll> to_remove;
    set<ll> to_add;
    for (ll y : blacks[x]) {
      bool added = 0;
      if (y > 0 && s1.find(y-1) != s1.end()) {
        to_add.insert(y);
        added = 1;
      }
      if (y < 2*n && s1.find(y+1) != s1.end()) {
        to_add.insert(y);
        added = 1;
      }
      if (!added && s1.find(y) != s1.end()) to_remove.insert(y);
    }
    for (auto y : to_remove) {
      s1.erase(s1.find(y));
    }
    for (auto y : to_add) {
      s1.insert(y);
    }
  }
  cout << s1.size() << endl;
  return 0;
}
