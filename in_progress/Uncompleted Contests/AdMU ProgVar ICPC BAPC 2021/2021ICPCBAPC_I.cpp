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
int t[N], s[N];
pii st[N];
int n;

bool opt(ll x) {
  ll currtime = 0;
  ll comptime = 0;
  for (int i = 0; i < n; i++) {
    ll time = st[i].first;
    ll req = st[i].second;
    if (time == -1) continue;

    comptime += x*(time-currtime);
    comptime -= req;
    currtime = time;
    if (comptime < 0) return false;
  }
  return true;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n; 
  for (int i = 0; i < n; i++) cin >> t[i];
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++) st[i] = {s[i], t[i]};

  sort(st, st+n);

  int lo = 1;
  int hi = 1e9;
  int ans = 0;
  while (lo <= hi) {
    int mid = hi-(hi-lo)/2;
    if (opt(mid)) {
      ans = mid;
      hi = mid-1;
    }
    else lo = mid+1;
  }

  cout << ans << endl;
  
  
  return 0;
}
