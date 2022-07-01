/*
  Handle the LCM terms separately.
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
  return gcd(b,a%b);
}

ll lcm(ll a, ll b) {
  return a/gcd(a,b)*b;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, a, b, p, q; cin >> n >> a >> b >> p >> q;
  ll diva = n/a;
  ll divb = n/b;
  ll divab = n/lcm(a,b);
  cout << (diva-divab)*p + (divb-divab)*q + divab*max(p,q) << endl;
  
  return 0;
}
