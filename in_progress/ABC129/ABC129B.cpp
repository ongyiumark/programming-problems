/*
  Check every possible splitting.
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

const int N = 100;
int dp[N*N+5];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  int w[n];
  for (int i = 0; i < n; i++){
    cin >> w[i];
  }
  for (int i = 1; i < n; i++){
    w[i] += w[i-1];
  }

  int score = 1e9;
  for (int i = 0; i < n; i++){
    score = min(score, abs(w[n-1]-2*w[i]));
  }

  cout << score << endl;
  
  
  return 0;
}
