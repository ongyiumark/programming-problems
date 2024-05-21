/*
  Do a range update +1 from L to R. This can be done with a difference array.
  Then, check for the indexes that are equal to m.
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
int diff[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, m; cin >> n >> m;
  memset(diff, 0, sizeof diff);
  for (int i = 0; i < m; i++){
    int l, r; cin >> l >> r;
    diff[l]++;
    diff[r+1]--;
  }

  int cnt = 0;
  for (int i = 1; i <= n; i++){
    diff[i] += diff[i-1];
    cnt += diff[i] == m;
  }
  cout << cnt << endl;
  return 0;
}
