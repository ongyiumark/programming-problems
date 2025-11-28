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

int main(){
  cin.tie(0)->sync_with_stdio(false);
  int n; cin >> n;
  vector<ii> ar(n);
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    ar[i] = {x, i};
  }
  sort(ar.begin(), ar.end(), greater<ii>());

  ll total = 0;
  set<ll> s;
  s.insert(-1); s.insert(n);
  for (int i = 0; i < n; i++) {
    ll curr = ar[i].second;
    set<ll>::iterator it = s.lower_bound(curr);
    int a = -1, b = -1, c = n, d = n;

    b = *prev(it);
    c = *it;
    if (b != -1) a = *prev(prev(it));
    if (c != n) d = *next(it);
    
    int val = ar[i].first;
    total += val*((b-a)*(c-curr) + (d-c)*(curr-b));
    s.insert(curr);
  }
  cout << total << "\n";
  return 0;
}
