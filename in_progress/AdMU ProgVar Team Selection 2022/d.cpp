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

const int N = 1e5+5;
const ll INF = 1e18;
vector<ll> X(N), Y(N), tX(N), tY(N);


ll calculate(vector<ll> &ar, int n, ll x) {
  ll res = 0;
  for (int i = 0; i < n; i++) res += abs(x-ar[i]);
  return res;
}

ll solve(vector<ll> &ar, int n) {
  if (n == 1) return ar[0];
  return ar[(n-1)/2];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int w, h; cin >> w >> h;
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> X[i] >> Y[i];
    tX[i] = X[i]; tY[i] = Y[i];
  }

  sort(tX.begin(), tX.begin()+n);
  sort(tY.begin(), tY.begin()+n);

  ll ansX = solve(tX, n);
  ll ansY = solve(tY, n);

  ll res = 0;
  ll highest = 0;
  for (int i = 0; i < n; i++) {
    ll tmp = abs(ansX-X[i]) + abs(ansY-Y[i]);
    res += tmp;
    highest = max(highest, tmp);
  }

  cout << res*2-highest << endl;
  cout << ansX << " " << ansY << endl;


  return 0;
}
