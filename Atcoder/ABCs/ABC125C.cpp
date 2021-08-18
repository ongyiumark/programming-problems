/*
  Suppose that we remove the ith integer. The highest possible GCD would be the GCD of the other integers
    without the one we removed.
  
  This is because GCD(a,b) <= a,b. We can't make it larger than the GCD of the others. 
  For the same reason, we can always be sure that this GCD is lower than 1e9.

  So, we can just do a ranged GCD query with a segment tree. 
  I realize that this is probably overkill, but this is the first solution that came to mind.

  P.S. I just looked at my old solution. We can also maintain a prefix GCD and suffix GCD to solve the same problem.
    This is because all the queries either start at 0 or end at n-1.
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
int n;

ll gcd(ll a, ll b){
  if (b==0) return a;
  return gcd(b, a%b);
}

struct segtree{
  int i, j;
  ll val, temp_val = 0;
  segtree *l, *r;
  segtree(vector<ll> &ar, int _i, int _j) : i(_i), j(_j) {
    if (i == j) {
      val = ar[i];
      l = r = NULL;
    } else {
      int k = (i+j) >> 1;
      l = new segtree(ar, i, k);
      r = new segtree(ar, k+1, j);
      val = gcd(l->val, r->val);
    }
  }

  ll query(int _i, int _j){
    if (_i > _j) return 0;
    if (_i <= i && j <= _j) return val;
    else if (_j < i || j < _i) return 0;
    else return gcd(l->query(_i,_j), r->query(_i,_j));
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];
  segtree *st = new segtree(A, 0, n-1);

  ll hi = st->query(0, n-1);
  for (int i = 0; i < n; i++) {
    ll tmp = gcd(st->query(i+1, n-1), st->query(0,i-1));
    hi = max(hi, tmp);
  }
  cout << hi << endl;
  return 0;
}
