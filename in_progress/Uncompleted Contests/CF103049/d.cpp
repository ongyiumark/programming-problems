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

const int N = 1e6;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int randint(int l, int r) { return uniform_int_distribution<int>(l,r)(rng); }

ll guess(int x, int y){
  cout << x << " " << y << endl;
  ll d; cin >> d;
  return d;
}

ll is_square(ll x){
  if (x < 0) return -1;
  ll sq = floor(sqrtl(x));
  if (sq*sq == x) return sq;
  else return -1;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  for (int k = 0; k < n; k++){
    int x = randint(0,N);
    int y = randint(0,N);
    ll d2 = guess(x,y);
    
    bool found = (d2 == 0);
    for (ll i = 0; i*i <= d2  && !found; i++){
      ll j = is_square(d2-i*i);
      if (j == -1) continue;
      if (j > N) continue;

      int nx = x;
      int ny = y;
      for (int di = -1; di <= 1 && !found; di++){
        for (int dj = -1; dj <= 1 && !found; dj++){
          if (abs(di)+abs(dj) < 2) continue;
          nx = x+i*di;
          ny = y+j*dj;
          if (nx < 0 || nx > N || ny < 0 || ny > N) continue;
          ll nd2 = guess(nx,ny);
          if (nd2 == 0) found = true;
        }
      }
    }

  }
  return 0;
}
