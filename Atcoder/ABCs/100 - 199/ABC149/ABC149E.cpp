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

pair<ll, ll> get_count(vector<ll> &A, ll k) {
  int n = A.size();
  vector<ll> P(n+1);
  for (int i = 0; i < n; i++) P[i+1] = P[i] + A[i];

  ll total = 0, count = 0;
  for (int i = 0; i < n; i++) {
    if (2*A[i] < k) break;
    int lo = i;
    int hi = n-1;
    int j = -1;

    while(lo <= hi) {
      int mid = hi - (hi-lo)/2;
      if (A[i] + A[mid] >= k) {
        j = mid;
        lo = mid+1;
      }
      else hi = mid-1;
    }
    count += 1+2*(j-i);
    total += 2*A[i] + 2*(P[j+1]-P[i+1]) + 2*(j-i)*A[i];
  }

  return {count, total};
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll n, m; cin >> n >> m;
  vector<ll> A(n);
  for (int i = 0; i < n; i++) cin >> A[i];
  sort(A.rbegin(), A.rend());

  ll lo = 0;
  ll hi = 2e5+5;
  ll ans = 0;
  while(lo <= hi) {
    ll mid = hi - (hi-lo)/2;

    auto [count, total] = get_count(A, mid);
    if (count >= m) {
      ans = mid;
      lo = mid+1;
    }
    else hi = mid-1;
  }
  
  auto [count, total] = get_count(A, ans);
  cout << total - (count-m)*ans << "\n";

  return 0;
}
