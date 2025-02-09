#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ll,ll> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

bool check(vector<ii> &tmp) {
  // (y2-y1)/(x2-x1) == (y3-y2)/(x3-x2)
  auto [x1, y1] = tmp[0];
  auto [x2, y2] = tmp[1];
  auto [x3, y3] = tmp[2];
  
  bool res = (y2-y1)*(x3-x2) == (y3-y2)*(x2-x1);
  return res;
}

void solve(int i, vector<int> &x, vector<int> &y, vector<ii> &tmp, bool &found) {
  if (tmp.size() == 3) {
    if (check(tmp)) found = true;
    return;
  }

  for (int j = i; j < (int)x.size(); j++) {
    tmp.push_back({x[j], y[j]});
    solve(j+1, x, y, tmp, found);
    tmp.pop_back();
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  vector<int> x(n), y(n);

  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }

  bool found = false;
  vector<ii> tmp;
  solve(0, x, y, tmp, found);
  cout << (found ? "Yes" : "No") << "\n";

  return 0;
}
