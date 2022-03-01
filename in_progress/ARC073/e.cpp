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

const int N = 2e5+5;
ll X[N], Y[N];
int n;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> X[i] >> Y[i];
  }

  ll Rmax, Rmin, Bmax, Bmin;
  Rmax = Bmax = -1e18;
  Rmin = Bmin = 1e18;

  for (int i = 0; i < n; i++) {
    ll nRmax1, nRmin1, nBmax1, nBmin1;
    ll nRmax2, nRmin2, nBmax2, nBmin2;
    // X is red
    nRmax1 = max(Rmax, X[i]);
    nRmin1 = min(Rmin, X[i]);
    nBmax1 = max(Bmax, Y[i]);
    nBmin1 = min(Bmin, Y[i]);

    // Y is red
    nRmax2 = max(Rmax, Y[i]);
    nRmin2 = min(Rmin, Y[i]);
    nBmax2 = max(Bmax, X[i]);
    nBmin2 = min(Bmin, X[i]);

    if ((nRmax1-nRmin1)*(nBmax1-nBmin1) < (nRmax2-nRmin2)*(nBmax2-nBmin2)) {
      Rmax = nRmax1;
      Rmin = nRmin1;
      Bmax = nBmax1;
      Bmin = nBmin1;
    }
    else {
      Rmax = nRmax2;
      Rmin = nRmin2;
      Bmax = nBmax2;
      Bmin = nBmin2;
    }
  }

  cout << (Rmax-Rmin)*(Bmax-Bmin) << endl;
  return 0;
}
