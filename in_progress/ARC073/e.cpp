#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<pair<ll,ll>,int> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5+5;
ll X[N], Y[N]; 
piii pairedX[N], pairedY[N];
bool vis[N];
int n;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n;
  for (int i = 0; i < n; i++){
    ll x, y; cin >> x >> y;
    if (x > y) swap(x,y);
    X[i] = x; Y[i] = y;
    pairedX[i] = {{x,y},i};
    pairedY[i] = {{y,x},i};
  }
  sort(pairedX, pairedX+n);
  sort(pairedY, pairedY+n);
  memset(vis, 0, sizeof vis);

  ll Rmax, Rmin, Bmax, Bmin;

  int L = 0, R = n-1;
  if (pairedX[L].second == pairedY[R].second) R--;
  vis[pairedX[L].second] = 1;
  vis[pairedY[R].second] = 1;

  // min is R and max is R
  Rmin = pairedX[L].first.first;
  Rmax = pairedY[R].first.first;
  Bmin = pairedX[L].first.second;
  Bmax = pairedY[R].first.second;
  if (Bmax < Bmin) swap(Bmax, Bmin);

  for (int i = 0; i < n; i++){
    if (vis[i]) continue;
    if (Bmin <= X[i] && X[i] <= Bmax) continue;
    if (Bmin <= Y[i] && Y[i] <= Bmax) continue;
    if (Y[i] < Bmin) Bmin = Y[i];
    if (X[i] > Bmax) Bmax = X[i];
  }
  ll ans1 = (Rmax-Rmin)*(Bmax-Bmin);

  // min is R and max is B
  Rmin = pairedX[L].first.first;
  Bmax = pairedY[R].first.first;
  Bmin = pairedX[L].first.second;
  Rmax = pairedY[R].first.second;
  if (Bmax < Bmin) swap(Bmax, Bmin);

  for (int i = 0; i < n; i++) {
    if (vis[i]) continue;
    Rmax = max(Rmax,X[i]);
    Bmin = min(Bmin,Y[i]);
  }
  ll ans2 = (Rmax-Rmin)*(Bmax-Bmin);

  cout << min(ans1, ans2) << endl;
  return 0;
}
