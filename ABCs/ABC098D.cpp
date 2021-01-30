/*
  A segment A_l to A_r has equal xor and sum if all the elements have no bits in common pairwise.
  Since A_i < 2^20. The longest segment must be 20.
  By the pigeonhole principle, if we have a segment longer than 20, some bit will be repeated.

  So, we simply fix l and move right until we there are bits in common.
  The exeption to this limit of 20 are elements of 0.
  To fix this, we skip any contiguous segment of 0s. We only count nonzero numbers for the limit of 20.
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

const int N = 2e5;
int a[N];
int nonzero[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int i, j;
  i = j = 0;
  while(i < n){
    while(j < n && a[j] == 0){
      j++;
    }
    while(i < j){
      nonzero[i] = j;
      i++;
    }
    j++;
  }

  ll ans = 0;
  for (int l = 0; l < n; l++){
    int cnt = 0;
    ll sum_total = 0;
    ll xor_total = 0;
    int idx = l;
    while(cnt <= 20 && idx < n){
      sum_total += a[idx];
      xor_total ^= a[idx];
      if (sum_total == xor_total){
        ans += nonzero[idx]-idx;
      }
      cnt++;
      idx = nonzero[idx];
    }
  }

  cout << ans << endl;
  return 0;
}
