/*
  This can lead to precision errors, so make sure to use integers.
  In comparing b1/d1 and b2/d2, we can compare b1*d2 and b2*d1. 
    However, this can reach 1e24. So, we use __int128.

  Sort the telescopes in decreasing order of sensitivity, and sort the stars in decreasing order of a = b/d.
  Let f(i) be the number of stars that telescope i can detect.
  Let s(i) be the sensitivity of telescope i.
  Notice that if s(i) <= s(j), then f(i) >= f(j). Thus, we can solve this with two pointers.

  We only 'add' a star to our count if we haven't encountered a star in that line.
    The line of a star can be uniquely identified by (x',y',z') such that (x',y',z') is (x,y,z) in lowest terms.
    That is, we divided each term by the gcd of the three. 
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
  return gcd(b, a%b);
}

struct stars{
  ll x, y, z;
  __int128 b, d2;
  stars(ll _x, ll _y, ll _z, ll _b) : x(_x), y(_y), z(_z), b(_b){
    d2 = x*x+y*y+z*z;
    ll g = gcd(abs(x), abs(y));
    g = gcd(g, abs(z));
    x /= g; y/=g; z/=g;
  }
  bool operator<(const stars &other) const{
    return b*other.d2 > other.b*d2;
  }
};

vector<stars> arr;
const int N = 1e5;
pair<ll, int> teles[N];
int ans[N];

set<piii> us;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int s, t; cin >> s >> t;
  for (int i = 0; i < s; i++){
    ll x, y, z, b; cin >> x >> y >> z >> b;
    arr.push_back(stars(x,y,z,b));
  }
  sort(arr.begin(), arr.end());

  for (int i = 0; i < t; i++) {
    cin >> teles[i].first;
    teles[i].second = i;
  }
  sort(teles, teles+t, greater<pair<ll,int>>());

  int idx = 0;
  int cnt = 0;
  for (int i = 0; i < t; i++){
    
    while(idx < s && arr[idx].b >= arr[idx].d2*teles[i].first){
      if (us.find({arr[idx].x,{arr[idx].y, arr[idx].z}}) == us.end()){
        cnt++;
        us.insert({arr[idx].x,{arr[idx].y, arr[idx].z}});
      }
      idx++;
    }
    ans[teles[i].second] = cnt;
  }

  for (int i = 0; i < t; i++){
    cout << ans[i] << endl;
  }
  return 0;
}
