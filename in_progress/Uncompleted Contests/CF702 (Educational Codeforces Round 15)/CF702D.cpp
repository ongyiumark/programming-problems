/*
  If you write the time in terms of N, the number of times the car travels k kilometers 
    and differentiate. You will realize that either highest N or lowest N will give the optimal answer.
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

const ll INF = 1e18;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll d, k, a, b ,t; cin >> d >> k >> a >> b >> t;
  ll check = k*(a-b)+t;
  ll cost = INF;
  if (check > 0) cost = min(k,d)*a + (d-min(k,d))*b;
  else {
    ll n = d/k;
    if (n > 0) cost = n*(a-b)*k + (n-1)*t + d*b;
    
    ll m = (d+k-1)/k;
    cost = min(cost, (m-1)*t + d*a);
  }
  cout << cost << endl;

  return 0;
}
