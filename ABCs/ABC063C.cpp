/*
  Simple possible sum dp.
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

const int N = 100;
bool dp[N*N+1];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  memset(dp, 0, sizeof dp);
  dp[0] = 1;
  for (int i = 0; i < n; i++){
    int s; cin >> s;
    for (int j = N*N; j >= 0; j--){
      if (dp[j]) dp[j+s] = 1;
    }
  }
  int j;
  for (j = N*N; j >= 1; j--){
    if (dp[j] && j%10 != 0){
      break;
    }
  }
  cout << j << endl;
  return 0;
}
