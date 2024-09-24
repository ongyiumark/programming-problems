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

vector<ii> moves;
ll k, sy;

void solve(ll x, ll y) {
  if (x == 0 && y == 0) return;
  if (x > 0) {
    if (x < k) {
      moves.push_back({x, (k-x)});
      solve(0, y-(k-x));
    }
    else if (x%2 == 0 && x < 2*k) {
      moves.push_back({x/2, k-x/2});
      moves.push_back({x/2, -(k-x/2)});
      solve(0, y);
    }
    else {
      moves.push_back({k, 0});
      solve(x-k, y);
    }
    return;
  }

  if (y < 0) {
    assert(y%2 == 0);
    moves.push_back({k+y/2, y/2});
    moves.push_back({-(k+y/2), y/2});
    return;
  }

  if (y%2 == 0 && y < 2*k) {
    moves.push_back({k-y/2, y/2});
    moves.push_back({-(k-y/2), y/2});
    return;
  }
  if (y >= k) {
    moves.push_back({0, k});
    solve(x, y-k);
    return;
  }

  assert(y%2 == 0);
  moves.push_back({k-y/2, y/2});
  moves.push_back({-k+y/2, y/2});
}

int main(){
  cin.tie(0)->sync_with_stdio(false);

  ll x, y; cin >> k >> x >> y;
  if ((x+y)%2 != k%2) {
    cout << -1 << "\n";
    return 0;
  }

  int sx = abs(x)/x;
  sy = abs(y)/y;
  solve(abs(x), abs(y));


  ll px = 0, py = 0;
  cout << moves.size() << "\n";
  for (auto [dx, dy] : moves) {
    px += sx*dx;
    py += sy*dy;
    assert(abs(dx) + abs(dy) == k);
    cout << px << " " << py << "\n";
  }



  
  return 0;
}
