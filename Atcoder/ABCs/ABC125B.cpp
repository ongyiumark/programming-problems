/*
  N is only up to 20, so we can try all 2^20 possibilities.
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

int C[20], V[20];
int n;

int solve(int i){
  if (i == n) return 0;
  return max(solve(i+1), V[i]-C[i]+solve(i+1));
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> V[i];
  for (int i = 0; i < n; i++) cin >> C[i];
  cout << solve(0) << endl; 
  return 0;
}
