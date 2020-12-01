#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5;
ll b[N];

ll gcd(ll a, ll b){
  if (b == 0) return a;
  return gcd(b, a%b);
}

ll lcm(ll a, ll b){
  return a/gcd(a,b)*b;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++){
    ll a; cin >> a;
    b[i] = a/2;
  }

  ll multiple = 1;
  for (int i = 0; i < n; i++){
    multiple = lcm(multiple, b[i]);
  }

  bool valid = true;
  for (int i = 0; i < n; i++){
    valid &= (multiple/b[i] % 2 == 1);
  }

  if (!valid){
    cout << 0 << endl;
    return 0;
  }

  cout << (m/multiple + 1)/2 << endl;

  return 0;
}
