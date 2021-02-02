/*
  We want to know how many pairs (k, b) have gcd(k,b) = 1.
  Let f(n) be the number of pairs (k,b) such that gcd(k,b) = n.
  So, we can rephrase the question to |k||b| - f(2) - f(3) - .... - f(1e6).

  To get f(2), count how many pairs (k, b) are divisible by 2.
  However, we need to subtract the pairs that have gcd(k,b) = 2i for i >= 2.
  That is, f(2) = |k_2||b_2| - f(4) - f(6) - ... - f(1e6).
  More generally, f(x) = |k_x||b_x| - f(2x) - f(3x) - ... 

  So, first we count how many elements of k are divisible by 2 ... 1e6. Do the same for b.
  To do this, we can maintain a frequency array of k.
  For each i <= 1e6, we add freq[i*j] to freq[i] for j >= 2.

  Next, we solve for f(1e6) to f(1).
  Alternatively, we can do recursion with memoization.
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

const int N = 1e6+1;
ll cntk[N], cntb[N];
ll dp[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int k, b; cin >> k >> b;
  memset(cntk, 0, sizeof cntk);
  memset(cntb, 0, sizeof cntb);
  for (int i = 0; i < k; i++){
    int x; cin >> x;
    cntk[x]++;
  }
  for (int i = 0; i < b; i++){
    int x; cin >> x;
    x--;
    cntb[x]++;
  }

  for (int i = 1; i < N; i++){
    for (int j = 2; i*j < N; j++){
      cntk[i] += cntk[i*j];
      cntb[i] += cntb[i*j];
    }
  }

  for (int i = N-1; i >= 1; i--){
    dp[i] = cntk[i]*cntb[i];
    for (int j = 2; i*j < N; j++){
      dp[i] -= dp[i*j];
    }
  }

  cout << dp[1] << endl;
  return 0;
}
