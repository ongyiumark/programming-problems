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

const int M = 95;
ll P[M], N[M];
int m;

bool check(ll x){
  ll ogx = x;
  map<ll,ll> factors;
  map<ll,ll> cards;
  for (int i = 0; i < m; i++){
    cards[P[i]] = N[i];
  } 
  for (int d = 2; d <= 499 && x > 1; d++){
    while(x%d==0){
      x/=d;
      factors[d]++;
    }
  }
  if (x > 1) return false;

  for (auto it : factors) {
    if (cards[it.first] < it.second) return false;
    cards[it.first]-=it.second;
  }

  ll sum = 0;
  for (auto it : cards){
    sum += it.first*it.second;
  }
  return sum==ogx;
}
void testcase(){
  cin >> m;
  ll total = 0;
  for (int i = 0; i < m; i++) {
    cin >> P[i] >> N[i];
    total += P[i]*N[i];
  }
  
  ll ans = 0;
  for (int i = 0; i <= min(499*60LL,total); i++){
    if (check(total-i)) {
      cout << total-i << endl;
      return;
    }
  }
  cout << 0 << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  for (int x = 1; x <= t; x++){
    cout << "Case #" << x << ": ";
    testcase();
  }
  return 0;
}
