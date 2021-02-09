/*
  I found a smart way to compute the mex.
  If you write a few cases down, you'll notice that mex(qk) = q.
  Also, for all floor(a/k) = q, mex(a) = mex(a-q-1).
    This is because it cycles in a permutation of 0...q.

  So, we can come up with a recursive formula. 
  Let a = qk + r.
    If r%(q+1) = 0, mex(a) = q.
    Otherwise, mex(a) = mex(qk+r%(q+1)-(q+1)).
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

int mex(int a, int k){
  int q = a/k;
  int r = a%k;
  if (q == 0) return 0;
  r %= q+1;
  if (r == 0) return q;
  return mex(q*k+r-q-1, k);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++){
    int a, k; cin >> a >> k;
    ans ^= mex(a,k);
  }
  cout << (ans == 0 ? "Aoki" : "Takahashi") << endl;
  return 0;
}
