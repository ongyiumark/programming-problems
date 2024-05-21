/*
  I just found a working algorithm for when m >= 2. Then, I went through the all possibilities for when m = 0,1.
  First thing to notice is that when k >= 2^m, then it's impossible.
    This is because a XOR b <= 2^(MAX_BIT)-1.
  
  When k = 0, it's always possible. Just do 0011223344...
  Note also that m = 1, k = 1 is impossible.

  Consider the case whem m = 2.
  We know that k must be one of the integers, so we consider what to put between the two k's.
  Because of how XOR works, we know that the XOR of the numbers between the k's total to k.
    So, k [abcd..] k where a XOR b XOR c XOR d ... = k.
  
  We also now that every number have an 'inverse' under k. That is, for every integer a, there exist an integer b
    such that a XOR b = k. In fact, b = a XOR k.
  
  If we can insert an odd number of these pairs between the k's, then we are done. 
  For example, 'k ab k' or 'k ab cd ef k' and so on.
  This can be done if the number of integers is divisible by 4, i.e., m >= 2.

  Note that the 'inverse' of 0 is k, so it might be a problem.
  But, we can put it in a lot of places (any span that totals to k) since it doesn't affect the XOR sum. 
  
  Finally, we simply refect the numbers after the second k. 
  This will cancel all of the numbers except for k, satisfying the condition.
  For example, 'k ab cd ef k fe dc ba'.
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

int m, k; 
vector<int> ans;
const int N = 2e5;
bool vis[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> m >> k;
  
  if (k >= (1<<m)) {
    cout << -1 << endl;
    return 0;
  }

  if (k == 0){
    for (int i = 0; i < (1<<m); i++){
      cout << i << " " << i;
      cout << (i == (1<<m)-1 ? "\n" : " "); 
    }
    return 0;
  }

  if (m == 1) {
    cout << -1 << endl;
    return 0;
  }

  ans.push_back(0);
  ans.push_back(k);
  ans.push_back(0);

  memset(vis, 0, sizeof vis);
  vis[0] = 1;
  vis[k] = 1;

  stack<int> tmp;
  for (int i = 0; i < (1<<m); i++){
    if (vis[i]) continue;
    
    vis[i] = 1;
    vis[i^k] = 1;
    ans.push_back(i);
    ans.push_back(i^k);

    tmp.push(i);
    tmp.push(i^k);
  }

  ans.push_back(k);
  while(!tmp.empty()){
    ans.push_back(tmp.top());
    tmp.pop();
  }

  int n = ans.size();
  for (int i = 0; i < n; i++){
    cout << ans[i];
    cout << (i == n-1 ? "\n" : " ");
  }
  return 0;
}
