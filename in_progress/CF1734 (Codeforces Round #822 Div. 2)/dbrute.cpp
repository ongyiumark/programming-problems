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

const int N = 2e5+5;
ll a[N];
ll pref[N];
int n, k;

map<pii,bool> memo;
ll range(int l, int r) {
  return pref[r]-pref[l-1];
}


bool solve(int l, int r) {
  if (memo.find({l,r}) != memo.end()) return memo[{l,r}];
  if (l == 1 || r == n) return true;

  if (r < n && range(l, r+1) >= 0) memo[{l,r}] |= solve(l,r+1);
  if (l > 1 && range(l-1, r) >= 0) memo[{l,r}] |= solve(l-1,r); 

  return memo[{l,r}];
}

void testcase() {
  cin >> n >> k;
  a[0] = 0; a[n+1] = 0;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 0; i <= n+1; i++) {
    pref[i] = a[i];
    if (i > 0) pref[i] += pref[i-1];
  }
  memo.clear();

  cout << (solve(k,k) ? "YES" : "NO") << "\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while(t--) testcase();

  return 0;
}