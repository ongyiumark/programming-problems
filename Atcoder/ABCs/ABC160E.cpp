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

struct apple {
  // 0 = red, 1 = green, 2 = colorless
  ll d, color;

  bool operator<(const apple& other) const {
    return d > other.d;
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int x, y, a, b, c; cin >> x >> y >> a >> b >> c;
  vector<apple> apples;

  for (int i = 0; i < a; i++) {
    int d; cin >> d;
    apples.push_back({d, 0});
  }
  for (int i = 0; i < b; i++) {
    int d; cin >> d;
    apples.push_back({d, 1});
  }
  for (int i = 0; i < c; i++) {
    int d; cin >> d;
    apples.push_back({d, 2});
  }

  sort(apples.begin(), apples.end());
  int taken = 0, currx = 0, curry = 0;
  vector<bool> take(a+b+c);
  for (int i = 0; i < a+b+c; i++) {
    auto &[d, color] = apples[i];
    if (color == 0 and currx < x and taken < x+y) {
      currx++; taken++;
      take[i] = true;
    }

    if (color == 1 and curry < y and taken < x+y) {
      curry++; taken++;
      take[i] = true;
    }

    if (color == 2 and taken < x+y) {
      taken++;
      take[i] = true;
    }
  }

  ll total = 0;
  for (int i = 0; i < a+b+c; i++) {
    total += (take[i] ? apples[i].d : 0);
  }
  cout << total << "\n";

  
  return 0;
}
