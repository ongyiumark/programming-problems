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

struct circle {
  ll x, y, r;

  ll inside(ll a, ll b) {
    ll dx = x-a;
    ll dy = y-b;
    return dx*dx + dy*dy < r*r;
  }

  void scale(ll mult) {
    x *= mult;
    y *= mult;
    r *= mult;
  }
};

istream& operator>>(istream &is, circle &c) {
  is >> c.x >> c.y >> c.r;
  return is;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  circle circs[n];
  for (int i = 0; i < n; i++) {
    cin >> circs[i];
  }

  ll ans = 0;

  ll mult = 69;
  for (int i = 0; i < n; i++) {
    circs[i].scale(mult);
  }
  for (ll i = -10*mult; i <= 20*mult; i++) {
    for (ll j = -10*mult; j <= 20*mult; j++) {
      ll xs[] = {i,i+1,i,i+1};
      ll ys[] = {j,j,j+1,j+1};
      int cnt = 0;
      for (int k = 0; k < 4; k++) {
        bool inside = 0;
        for (int l = 0; l < n; l++) {
          if (circs[l].inside(xs[k], ys[k])) {
            inside = 1;
            break;
          }
        }
        cnt += inside;
      }
      if (cnt == 4) ans++;
    }
  }

  cout << setprecision(12) << fixed << (ld)ans/(mult*mult) << endl;



  return 0;
}
