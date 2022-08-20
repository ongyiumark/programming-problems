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
vector<ll> v(N);
vector<pair<ll,int>> qr(N);
vector<ll> ans(N);
int n; 

bool solve(int k, ll t) {
  int cnt = 1;
  ll curr = 0;
  for (int i = 0; i < n; i++) {
    if (curr + v[i] > t) {
      curr = 0;
      cnt++;
    } 
    curr += v[i];
  }
  return cnt <= k;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  ll hi = -1e18;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    hi = max(hi, v[i]);
  }
  
  int q; cin >> q;
  for (int i = 0; i < q; i++) {
    int t; cin >> t;
    qr[i] = {t, i};
  }
  sort(qr.begin(), qr.begin()+q, greater<pair<ll,int>>());
  int curr = 1;
  for (int i = 0; i < q; i++) {
    int t = qr[i].first;
    while(curr <= n && !solve(curr,t)) {
      curr++;
    }
    ans[i] = curr;
    if (curr > n) ans[i] = -1;
  }



  for (int i = 0; i < n; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}
