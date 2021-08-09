/*
  If you try a greedy approach, you'll eventually realize that it doesn't work.
  So, the next step is to try some DP.

  Let DP[i] be the maximum number using i matchsticks.
  We can't store the number in 64-bits so we use a string with a custom comparator. 
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

int sticks[] = {0,2,5,5,4,5,6,3,7,6};

const int N = 1e4+5;
int A[10];

string dp[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) cin >> A[i];

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == 0 || dp[i].size() > 0) {
        if (i + sticks[A[j]] <= n) {
          dp[i+sticks[A[j]]] = max(dp[i+sticks[A[j]]], dp[i]+to_string(A[j]), 
          [](const string &left, const string &right){
            if (left.size() < right.size()) return true;
            if (left.size() == right.size()) return left < right;
            return false;
          });
        }
      }
    }
  }

  cout << dp[n] << endl;
  
  return 0;
}
