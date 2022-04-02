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

bool isinteresting(ll x){
  ll prod = 1;
  ll sum = 0;
  while(x > 0){
    sum += x%10;
    prod *= x%10;
    x /= 10;
  }
  return prod%sum == 0;
}
ll solve(ll n) {
  if (n == 0) return 0;
  ll cnt = 0;
  for (int i = 1; i <= n; i++){
    cnt += isinteresting(i);
  }
  return cnt;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int cnt = 0;
  for (char c : "01") {
    cnt++;
  }
  cout << cnt << endl;

  return 0;
}
