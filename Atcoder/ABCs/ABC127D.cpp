/*
  It's optimal for the lowest A to change into the highest C.
  So we start with the highest C[j], then change the lowest B[j] of A into C[j]
    as long as A[i] < C[j].
  
  If we do it this way, we don't have to got back to i = 0 for C[j+1].
  This is because all A[x] such that x < i is C[j] and C[j] >= C[j+1].
  This way the index i will only go through 0 to n-1 once. 
  
  Time complexity: O(M+N).
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

const int N = 1e5+5;
vector<ll> A(N);
vector<pair<ll, int>> arr(N);

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> A[i];

  for (int i = 0; i < m; i++){
    cin >> arr[i].second >> arr[i].first;
  }
  sort(arr.begin(), arr.begin()+m, greater<pair<ll,int>>());
  
  sort(A.begin(), A.begin()+n);

  int idx = 0;
  for (int i = 0; i < m && idx < n; i++){
    int b = arr[i].second;
    ll c = arr[i].first;
    while(idx < n && b > 0 && A[idx] < c){
      A[idx] = c;
      b--;
      idx++;
    }
  }

  ll ans = 0;
  for (int i = 0; i < n; i++){
    ans += A[i];
  }
  cout << ans << endl;
  return 0;
}
