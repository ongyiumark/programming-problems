/*
  Fix the first cut. Then, binary search the answer.
  An answer is valid if we can find two partitions that are at least that answer.
    This can be done with 2 binary searches along the indexes.
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
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n;
const int N = 1e5+5;
ll A[N];
ll prefA[N];

ll sum(int a, int m){
  int b = a+m-1;
  ll left = (a == 0 ? 0 : prefA[a-1]);
  if (b < n) return prefA[b]-left;
  else return prefA[n-1]-left+sum(0, b%n+1);
}

bool valid(int i, ll x){
  int lo = 1;
  int hi = n-1;
  int ans = -1;
  while(lo <= hi){
    int mid = hi - (hi-lo)/2;
    if (sum(i,mid) >= x){
      ans = mid;
      hi = mid-1;
    }
    else lo = mid+1;
  }
  if (ans == -1) return false;
  
  int b = (i+ans)%n;
  lo = 1;
  hi = (b > i ? i+n-b : i-b)-1;
  ans = -1;
  while(lo <= hi){
    int mid = hi - (hi-lo)/2;
    if (sum(b, mid) >= x){
      ans = mid;
      hi = mid-1;
    }
    else lo = mid+1;
  }
  if (ans == -1) return false;
  
  int c = (b+ans)%n;
  int len = (c > i ? i+n-c : i-c);
  return sum(c, len) >= x;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> A[i];
  }
  prefA[0] = A[0];
  for (int i = 1; i < n; i++){
    prefA[i] = A[i] + prefA[i-1];
  }

  // start at i.
  ll ans = 0;
  for (int i = 0; i < n; i++){
    ll lo = 1;
    ll hi = prefA[n-1];
    ll tmp = -1;
    while(lo <= hi){
      ll mid = hi-(hi-lo)/2;
      if (valid(i, mid)){
        tmp = mid;
        lo = mid+1;
      }
      else hi = mid-1;
    }
    ans = max(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}
