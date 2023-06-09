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

const int SZ = 1e7;
const int MX = 1e9;

vector<tuple<ll,ll,ll>> pts[MX/SZ+5][MX/SZ+5][MX/SZ+5];

ld dist(ll a1, ll a2, ll a3, ll b1, ll b2, ll b3) {
  return sqrtl((a1-b1)*(a1-b1) + (a2-b2)*(a2-b2) + (a3-b3)*(a3-b3));
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    ll x, y, z; cin >> x >> y >> z;

    ll nx = x/SZ;
    ll ny = y/SZ;
    ll nz = z/SZ;

    pts[nx][ny][nz].push_back({x,y,z});
  }

  ld ans = 1e18;
  for (int i = 0; i < MX/SZ+1; i++) {
    for (int j = 0; j < MX/SZ+1; j++) {
      for (int k = 0; k < MX/SZ+1; k++) {
        int sz = pts[i][j][k].size();

        for (int l = 0; l < sz; l++) {
          for (int m = l+1; m < sz; m++) {
            auto &[a1, a2, a3] = pts[i][j][k][l];
            auto &[b1, b2, b3] = pts[i][j][k][m];
            ans = min(ans, dist(a1, a2, a3, b1, b2, b3));
          }
        }


        for (int mask = 1; mask < 8; mask++) {
          bool di = (1<<0)&mask;
          bool dj = (1<<1)&mask;
          bool dk = (1<<2)&mask;
          for (auto &[a1, a2, a3] : pts[i][j][k]) {
            for (auto &[b1, b2, b3] : pts[i+di][j+dj][k+dk]) {
              ans = min(ans, dist(a1, a2, a3, b1, b2, b3));
            }
          }
        }
      }
    } 
  }

  cout << setprecision(20) << fixed;
  cout << ans << endl;
  
  return 0;
}
