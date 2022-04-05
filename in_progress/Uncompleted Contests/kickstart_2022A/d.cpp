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

map<int,int> factorize(int x){
  map<int,int> res;
  int d = 2;
  while (d*d <= x){
    while(x%d == 0){
      res[d] += 1;
      x /= d;
    }
    d++;
  }
  if (x > 1) res[x] += 1;
}

ll solve(ll n) {
  if (n == 0) return 0;
  ll cnt = 0;
  for (int total = 0; total <= 9*12; total++){
    map<int,int> facts = factorize(total);
    bool valid = true;
    for (auto it : facts) {
      if (it.second > 9) valid = false;
    }
    if (!valid) {
      // at least one 0 digit
      continue;
    }

    for (int len = 1; len < 12; len++) {
      if (len*9 < total) continue;
    }
  }
  return cnt;
}

void testcase() {
  ll a, b; cin >> a >> b;
  cout << solve(b)-solve(a-1) << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int T; cin >> T;
  for (int x = 1; x <= T; x++) {
    cout << "Case #" << x << ": ";
    testcase();
  }

  return 0;
}
