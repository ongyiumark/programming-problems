/*
  Solve for sum of maximum and sum of minimum separately.
  For each element, we count how many segments it is maximum on.
  We can do this by maintaining L[i] and R[i] pointing to the next largest element.
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

const int N = 1e6+5;
const int LOGN = 21;
pii a[N], b[N];
int L[N], R[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    b[i] = a[i] = {x,i};
  }

  sort(b, b+n);

  for (int i = 0; i < n; i++) {
    L[i] = i-1;
    R[i] = i+1;
  }

  ll maxcnt = 0;
  for (int i = 0; i < n; i++) {
    pii curr = b[i];
    auto [val, pos] = b[i];
    maxcnt += (ll)val*(R[pos]-pos)*(pos-L[pos]);

    if (L[pos] >= 0) R[L[pos]] = R[pos];
    if (R[pos] < n) L[R[pos]] = L[pos]; 
  }

  sort(b, b+n, greater<pii>());

  for (int i = 0; i < n; i++) {
    L[i] = i-1;
    R[i] = i+1;
  }

  ll mincnt = 0;
  for (int i = 0; i < n; i++) {
    pii curr = b[i];
    auto [val, pos] = b[i];
    mincnt += (ll)val*(R[pos]-pos)*(pos-L[pos]);

    if (L[pos] >= 0) R[L[pos]] = R[pos];
    if (R[pos] < n) L[R[pos]] = L[pos]; 
  }

  cout << maxcnt - mincnt << endl;


  return 0;
}
