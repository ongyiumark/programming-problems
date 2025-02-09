/* 
  The first thing to notice is that the gcd(x,y) <= min(x,y).
  So, the answer is simply the number of possible gcds less than the minimum of the set.

  Suppose we want to know if gcd({i..j}) = g is possible for some g.
  We can take all multiples of g from the set, and get the gcd of all of them.
  If the gcd of all the multiples of g is g, then it's possible. 
  Otherwise, it's going to be a multiple of g, which implies it's impossible.

  Let's consider a number A in the set.
  How many x <= A such that A is a multiple of x? That's the divisors of A.
  So, we get all the divisors of A and update our gcd table.
  We can maintain a gcd table with a hashmap.
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

ll gcd(ll a, ll b){
  if (b==0) return a;
  return gcd(b, a%b);
}
const int N = 2000;
ll a[N];
unordered_map<int, int> gcds;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  ll lo = 1e18;
  for (int i = 0; i < n; i++){
    cin >> a[i];
    lo = min(a[i], lo);
  }

  for (int i = 0; i < n; i++){
    for (int d = 1; d*d <= a[i]; d++){
      if (a[i]%d != 0) continue;
      gcds[d] = gcd(gcds[d], a[i]);
      gcds[a[i]/d] = gcd(gcds[a[i]/d], a[i]);
    }
  }

  int ans = 1;
  for (auto g : gcds){
    if (g.first == g.second && g.first < lo) ans++;  
  }
  cout << ans << endl;
  return 0;
}
