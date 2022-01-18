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
int A[N];
int lo[N], hi[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, l, r, k;
  cin >> n >> l >> r >> k;
  for (int i = 0; i < n; i++) cin >> A[i];

  hi[n-1] = r;
  lo[n-1] = l;
  for (int i = n-2; i >= 0; i--){
    if (A[i] == A[i+1]){
      lo[i] = lo[i+1];
      hi[i] = hi[i+1];
    }
    else if (A[i] < A[i+1]){
      lo[i] = max(lo[i+1]-k,l);
      hi[i] = hi[i+1]-1;
    }
    else {
      lo[i] = lo[i+1]+1;
      hi[i] = min(hi[i+1]+k,r);
    }
  }

  bool valid = true;
  for (int i = 0; i < n; i++){
    if (lo[i] > hi[i]) valid = false;
  }

  if (!valid){
    cout << -1 << endl;
    return 0;
  } 

  int curr = lo[0];
  cout << curr;
  for (int i = 1; i < n; i++){
    if (A[i-1] < A[i]){
      curr = max(curr+1,lo[i]);
    }
    else if (A[i-1] > A[i]){
      curr = max(curr-k,lo[i]);
    }
    cout << " " << curr;
  }
  cout << endl;

  return 0;
}
