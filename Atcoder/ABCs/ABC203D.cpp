/*
  Binary search the answer. A median of <= x is possible if there are k*k/2 + 1 numbers lower than or equal to x.
  We can count how many numbers less than or equal to x in a square with a 2D prefix sum.
*/ 
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
using ordered_set = __gnu_pbds::tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 805;
ll A[N][N];
ll n, k; 
ll cnt[N][N];

bool valid(ll x) {
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cnt[i][j] = (A[i][j] <= x);
      if (i == 0 && j == 0) continue;
      else if (i == 0) cnt[i][j] += cnt[i][j-1];
      else if (j == 0) cnt[i][j] += cnt[i-1][j];
      else cnt[i][j] += cnt[i-1][j] + cnt[i][j-1] - cnt[i-1][j-1];
    }
  }

  if (cnt[k-1][k-1] >= k*k/2 + (k%2)) return true;
  for (int i = k; i < n; i++) {
    for (int j = k; j < n; j++) {
      ll res = cnt[i][j] - cnt[i][j-k] - cnt[i-k][j] + cnt[i-k][j-k];
      if (res >= k*k/2 + (k%2)) return true;
    }
  }
  return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> A[i][j]; 
    }
  }

  ll lo = 0;
  ll hi = 1e9;
  ll ans = hi;

  while(lo <= hi) {
    ll mid = hi - (hi-lo)/2;
    if (valid(mid)) {
      ans = mid;
      hi = mid-1;
    }
    else lo = mid+1;
  }
  cout << ans << endl;
  
  return 0;
}
