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
ll n, p, k, total;
ll d[N];
ll pref[2*N], nextday[N], passes[N];
int vis[N];

ll range(int l, int r) {
  if (r < l) return 0;
  if (l == 0) return pref[r];
  return pref[r]-pref[l-1];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n >> p >> k;
  for (int i = 0; i < n; i++) cin >> d[i];
  for (int i = 0; i < n; i++) total += d[i];
  for (int i = 0; i < 2*n; i++) {
    pref[i] = d[i%n];
    if (i > 0) pref[i] += pref[i-1];
  }  
  
  // Precomputing next day.
  memset(passes, 0, sizeof passes);
  for (int i = 0; i < n; i++) {
    int lo = i;
    int hi = 2*n-1;
    int ans = -1;
    while(lo <= hi) {
      int mid = hi - (hi-lo)/2; 
      ll tmp = range(i, mid);
      if (tmp <= p%total) {
        ans = mid;
        lo = mid+1;
      }
      else hi = mid-1;
    }
    nextday[i] = (ans+1)%n;

    ll t = range(i, n-1);
    if (t <= p) passes[i] = (p-t)/total + 1;
  }

  ll ans = 0;
  int cur = 0, last = 0;
  int cnt = 0;
  memset(vis, -1, sizeof vis);
  while (vis[cur] == -1) {
    vis[cur] = cnt;
    cur = nextday[cur];
    last = cur;
    cnt++;
  }
  int cycle = cnt-vis[cur];
  int start = cnt-cycle;

  ll cyclecnt = 0;
  for (int i = 0; i < cycle; i++) {
    cyclecnt += passes[cur];
    cur = nextday[cur];
  }
  
  if (k <= start) {
    cur = 0;
    while(k--) {
      ans += passes[cur];
      cur = nextday[cur];
    }
    cout << ans << endl;
    return 0;
  }

  cur = 0;
  for (int i = 0; i < start; i++) {
    k--;
    ans += passes[cur];
    cur = nextday[cur];
  }

  ans += cyclecnt*(k/cycle);
  k %= cycle;

  while(k--) {
    ans += passes[cur];
    cur = nextday[cur];
  }

  cout << ans << endl;
  return 0;
}
