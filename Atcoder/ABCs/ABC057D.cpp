/*
  The maximum average can be solved by sorting in non-increasing order and getting the first a.
  Two cases:
  (1) All the same
    In this case, you have to account for different sizes of subsets.
  (2) Only the last few are the same
    Simply count how many times that number appears in the whole set 'choose' the number of times in the subset.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int N = 50;
ll v[N];

ll comb[N+1][N+1];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  memset(comb, 0, sizeof comb);
  for (int i = 0; i <= N; i++){
    for (int j = 0; j <= i; j++){
      if (i == 0 || j == 0) comb[i][j] = 1;
      else comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
    }
  }
  
  ll n, a, b; cin >> n >> a >> b;
  for (int i = 0; i < n; i++){
    cin >> v[i];
  }

  sort(v, v+n, greater<ll>());
  ll total = 0;
  for (int i = 0; i < a; i++){
    total += v[i];
  }
  ld avg = (ld)total/a;
  
  cout << setprecision(10) << fixed << avg << endl;
  int all_count = count(v, v+n, v[a-1]);
  int in_count = count(v, v+a, v[a-1]);
  if (in_count == a){
    ll ans = 0;
    for (int i = a; i <= b; i++){
      if (v[i-1] != v[a-1]) break; 
      ans += comb[all_count][i];
    }
    cout << ans << endl;
  }
  else cout << comb[all_count][in_count] << endl;
  return 0;
}
