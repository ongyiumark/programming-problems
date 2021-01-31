/*
  Let snuke(n) be the smallest snuke number greater than or equal to n.
  We can list the snuke numbers by iterating on n := snuke(n+1)

  The smallest snuke number greater than or equal to n is the number x >= n that minimizes x/S(x).
  The first observation is that x must have the same number of digits as n.
  This is because 99...999 is a snuke number.

  Let A = 99...999. To prove this, we need to show that all numbers x greater than A have x/S(x) >= A/S(A).
  Suppose that A has d digits. Lets consider all numbers B that have d+1 digits.
  If S(B) <= S(A), then B/S(B) > A/S(A).
  If S(B) = S(A)+b, the smallest number that satisfies this condition is in the form b*10^d + A.
    (b*10^d + A)/(S(A)+b) > A/S(A)
    S(A)*b*10^d > A*b
    S(A)*10^d > A     Q.E.D.
  By a similar procedure, we can show that for A' = 99..999 with d+1 digits, 
    all numbers B' that have d+2 digits also have B'/S(B') > A'/S(A').

  The next observation is that snuke(n) is obtained by changing the last k digits of n for some k.
  We simply try all possible k's and get the minimum.
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

ll digit_sum(ll x){
  ll ans = 0;
  while(x > 0){
    ans += x%10;
    x/=10;
  }
  return ans;
}

ll snuke(ll x){
  ll ans = x;
  ld lo = (ld)x/digit_sum(x);
  
  string s = to_string(x);
  int n = s.size();
  for (int i = n-1; i >= 0; i--){
    s[i] = '9';
    ll t = stoll(s);
    ld curr = (ld)t/digit_sum(t);
    if (lo > curr){
      lo = curr;
      ans = t;
    }
  }
  return ans;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll k; cin >> k;
  ll x = 1;
  for (int i = 0; i < k; i++){
    cout << x << endl;
    x = snuke(x+1);
  }
  return 0;
}
