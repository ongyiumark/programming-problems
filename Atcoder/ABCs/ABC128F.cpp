/*
  First notice that N-1 must be in the form xA + (x-1)B where x is a positive integer.
    Then, we have x(A-B) = N-1-B.
    Hence, A-B must divide N-1-B.
    We let c = A-B and let k*c = N-1-B, and loop over all values of k and c.
  
  So, the answer is completely determined by k and c. 
  Notice that DP[k,c] = DP[k-1,c] + S[A] + S[n-1-A].

  The sequence goes 0 -> A -> A-B -> 2A-B -> 2A-2B -> ...
  However, it repeats whenever A-B divides A.
  We can compute how long the sequence is and we can also compute when the sequence repeats.
    We simply ignore it if it repeats before reaching its destination.
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
ll S[N];

map<pair<ll,ll>,ll> memo;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> S[i];
  
  ll best = 0;
  for (ll c = 1; c <= n-1; c++){
    for (ll k = 1; k*c < n-1; k++){
      ll B = n-1-k*c;
      ll A = c+B;
      int cnt = (n-1-A)/c*2+1;
      if (A%c == 0) {
        int rep = A/c*2;
        if (rep <= cnt) continue;
      }
      memo[{k,c}] = memo[{k-1,c}] + S[A] + S[n-1-A];
      best = max(memo[{k,c}], best);
    }
  }
  cout << best << endl;

  return 0;
}
