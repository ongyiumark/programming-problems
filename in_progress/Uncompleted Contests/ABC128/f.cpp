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

map<pair<int,int>,ll> memo;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> S[i];
  
  ll best = 0;
  for (ll c = 1; 2*c < n-1; c++){
    for (int k = 1; k*c < n-1; k++){
      
      //if (n-1-k*c >= k*c) break;
      memo[{k,c}] = memo[{k-1,c}] + S[k*c] + S[n-1-k*c];
      best = max(memo[{k,c}], best);
    }
  }
  cout << best << endl;

  return 0;
}
