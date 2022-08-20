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
int sparse_min[LOGN][N];
int sparse_max[LOGN][N];
int a[N];

ll get_min(int l, int r) {
  if (l == r) return sparse_min[0][l];
  int k = floor(log2(r-l+1));
  return min(sparse_min[k][l], sparse_min[k][r-(1<<k)+1]);
}

ll get_max(int l, int r) {
  if (l == r) return sparse_max[0][l];
  int k = floor(log2(r-l+1));
  return max(sparse_max[k][l], sparse_max[k][r-(1<<k)+1]);
}

ll solve(int l, int r) {
  if (r <= l) return 0;
  ll amax = get_max(l, r);
  ll amin = get_min(l, r);

  int lo = 1;
  int hi = r-l+1;
  int ans = -1;
  int pos = -1;
  while(lo <= hi) {
    int mid = hi-(hi-lo)/2;
    bool val = 0;
    for (int i = l; i+mid-1 <= r; i++) {
      if (get_max(i, i+mid-1) == amax && get_min(i, i+mid-1) == amin) {
        val = 1;  
        pos = i;
        break;
      }
    }
    if (val) {
      ans = mid;
      hi = mid-1;
    }
    else lo = mid+1;
  }

  int nl = pos;
  int nr = pos+ans-1;

  ll cnt = (ll)(nl-l+1)*(r-nr+1)*(amax-amin);

  //cout << nl << " " << nr << " " << amax <<  " " << amin << " " << cnt << endl;
  return cnt + solve(l, nr-1) + solve(nl+1, r);
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++) {
    sparse_min[0][i] = sparse_max[0][i] = a[i];
  }
  for (int k = 1; k < LOGN; k++) {
    for (int i = 0; i < n; i++) {
      int idx = i + (1<<(k-1));
      int other = 1e9;
      if (idx < n) other = sparse_min[k-1][idx]; 
      sparse_min[k][i] = min(sparse_min[k-1][i], other);
    }
  }

  for (int k = 1; k < LOGN; k++) {
    for (int i = 0; i < n; i++) {
      int idx = i + (1<<(k-1));
      int other = -1e9;
      if (idx < n) other = sparse_max[k-1][idx]; 
      sparse_max[k][i] = max(sparse_max[k-1][i], other);
    }
  }

  
  cout << solve(0, n-1) << endl;

  return 0;
}
