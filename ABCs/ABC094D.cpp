/*
  Notice that comb(n,k) <= comb(n+1,k).
  This means that is optimal to choose the largest n.

  Now, we simply need to choose a k that maximizes comb(M,k) where M is the maximum number in the sequence.
  To maximize this, we need to choose a k that is the closest to M/2.
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

const int N = 1e5;
int a[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  sort(a, a+n);
  int best = 0;
  int diff = 1e9;
  for (int i = 0; i < n-1; i++){
    int cdiff = abs(a[n-1]/2-a[i]);
    if (cdiff <= diff){
      diff = cdiff;
      best = a[i];
    }
  }
  cout << a[n-1] << " " << best << endl;
  return 0;
}
