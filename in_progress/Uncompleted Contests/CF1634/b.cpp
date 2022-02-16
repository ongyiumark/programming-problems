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
ll a[N];
map<pair<ll, int>, bool> memo;

ll n, x, y;
bool found = false;
void solve(ll d, int i){
  if (found) return;
  if (i == 0) {
    if (x == d || x+3 == d) found = true;
    if (x == d) cout << "Alice" << endl;
    else if (x+3 == d) cout << "Bob" << endl;
    return;
  }
  if (d >= a[i-1]) solve(d-a[i-1], i-1);
  solve(d^a[i-1], i-1);
}

void testcase(){
  cin >> n >> x >> y;
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  found = false;
  solve(y,n);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  for (int i = 0; i < t; i++){
    testcase();
  }
  return 0;
}
