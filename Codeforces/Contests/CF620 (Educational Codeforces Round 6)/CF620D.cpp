/*
  Precompute all sums of pairs for both A and B.
  For each sum in A, binary search the best corresponding sum in B.

  Since we're working with absolute value, the binary search is reversed 
    depending on the value of the sum in A.

*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,pair<int,int>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  ll a[n];
  for (int i = 0; i < n; i++) cin >> a[i];

  int m; cin >> m;
  ll b[m];
  for (int i = 0; i < m; i++) cin >> b[i];

  ll totalA = 0, totalB = 0;
  for (int i = 0; i < n; i++) totalA += a[i];
  for (int i = 0; i < m; i++) totalB += b[i];

  // WLOG totalA >= totalB 
  vector<ll> A, B;
  A.resize(n);
  for (int i = 0; i < n; i++) A[i] = a[i];
  B.resize(m);
  for (int i = 0; i < m; i++) B[i] = b[i];

  bool swapped = 0;
  if (totalA < totalB) {
    swapped = 1;
    swap(n, m);
    swap(totalA, totalB);

    A.resize(n);
    for (int i = 0; i < n; i++) A[i] = b[i];
    
    B.resize(m);
    for (int i = 0; i < m; i++) B[i] = a[i];
  }

  pii res[2] = {{-1,-1}, {-1,-1}};
  int cnt = 0;

  // One swap.
  ll best = totalA-totalB;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      totalA = totalA-A[i]+B[j];
      totalB = totalB-B[j]+A[i];

      if (best > abs(totalA-totalB)) {
        cnt = 1;
        res[0].first = i;
        res[0].second = j;
        best = abs(totalA-totalB);
      }
      // Revert.
      totalA = totalA+A[i]-B[j];
      totalB = totalB+B[j]-A[i];
    }
  }

  // Two swap.
  vector<piii> twosA, twosB;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      twosA.push_back({A[i]+A[j], {i,j}});
    }
  } 
  for (int i = 0; i < m; i++) {
    for (int j = i+1; j < m; j++) {
      twosB.push_back({B[i]+B[j], {i,j}});
    }
  } 
  sort(twosA.begin(), twosA.end());
  sort(twosB.begin(), twosB.end());

  int szB = twosB.size();
  for (auto [currA, pA] : twosA) {
    // totalA-totalB-2*currA+2*currB 
    int lo = 0;
    int hi = szB - 1;
    int ans = -1;
    ll curr = totalA-totalB-2*currA;
    while (lo <= hi) {
      int mid = hi - (hi-lo)/2;
      auto [currB, pB] = twosB[mid];
      if (curr > 0) {
        if (curr+2*currB >= 0) {
          hi = mid-1;
          ans = mid;
        }
        else lo = mid+1;
      }
      else {
        if (curr+2*currB >= 0) {
          lo = mid+1;
          ans = mid;
        }
        else hi = mid-1;        
      }
    }

    for (int idx : {ans-1, ans, ans+1}){
      if (idx < 0 || idx >= szB) continue;
      auto [currB, pB] = twosB[idx];
      ll tmp = abs(totalA-totalB-2*(currA-currB));
      if (best > tmp) {
        best = tmp;
        res[0] = {pA.first, pB.first};
        res[1] = {pA.second, pB.second};
        cnt = 2;
      } 
    }
  }
  
  if (swapped) {
    swap(res[0].first, res[0].second);
    swap(res[1].first, res[1].second);
  }

  // Print result.
  cout << best << endl;
  cout << cnt << endl;
  for (int i = 0; i < cnt; i++) {
    cout << res[i].first+1 << " " << res[i].second+1 << endl;
  }

  return 0;
}
