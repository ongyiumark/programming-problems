#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
  return a/gcd(a, b)*b;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll a, b, c, d; cin >> a >> b >> c >> d;  

  ll cd = lcm(c, d);
  ll div_cnt = (b/c - (a-1)/c) + (b/d - (a-1)/d) - (b/cd - (a-1)/cd);
  cout << (b-a+1)-div_cnt << "\n"; 
  
  return 0;
}
