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

  int p, u; cin >> p >> u;
  bool is_pinned[p+u+1], changed[p+u+1];
  memset(changed, 0, sizeof changed);
  deque<int> pin, unpin;
  for (int i = 0; i < p; i++) {
    int x; cin >> x;
    pin.push_back(x);
    is_pinned[x] = 1;
  }
  for (int i = 0; i < u; i++) {
    int x; cin >> x;
    unpin.push_back(x);
    is_pinned[x] = 0;
  }

  int pp, uu; cin >> pp >> uu;
  deque<int> pin_goal, unpin_goal;
  for (int i = 0; i < pp; i++) {
    int x; cin >> x;
    pin_goal.push_back(x);
  }
  for (int i = 0; i < uu; i++) {
    int x; cin >> x;
    unpin_goal.push_back(x);
  }

  int ans = 0;

  while(!pin_goal.empty()) {
    int curr = pin_goal.front();
    pin_goal.pop_front();

    while(!pin.empty() && pin.front() != curr) {
      int x = pin.front(); pin.pop_front();
      is_pinned[x] = 0;
      changed[x] = 1;
      ans++;
    }
    if (!pin.empty()) pin.pop_front();
    else {
      is_pinned[curr] = 1;
      ans++;
    }
  }
  
  while(!unpin_goal.empty()) {
    int curr = unpin_goal.back();
    unpin_goal.pop_back();

    while(!unpin.empty() && unpin.back() != curr) {
      int x = unpin.back(); unpin.pop_back();
      if (is_pinned[x]) continue;
      if (changed[x] && changed[curr]);
      else ans++;
      is_pinned[x] = 1;
    }

    if (!unpin.empty()) unpin.pop_back();
    else {
      is_pinned[curr] = 0;
      if (changed[curr]);
      else ans++;
    }
  }

  cout << ans << endl;
  

  return 0;
}
