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
  return a/gcd(a,b)*b;
}

struct fraction{
  ll a, b;
  
  fraction(ll a, ll b) : a(a), b(b) {}
  
  fraction simplify() const {
    ll na = a, nb = b;
    if (a < 0 && b < 0) na = -a, nb = -b;
    else if (b < 0) na = -a, nb = -b;

    ll g = gcd(abs(na), nb);
    return fraction(na/g, nb/g);
  }

  fraction operator+(const fraction &other) const {
    ll d = lcm(b, other.b);
    ll na = d/b*a + d/other.b*other.a;
    return fraction(na, d).simplify();
  }

  fraction operator-(const fraction &other) const {
    ll d = lcm(b, other.b);
    ll na = d/b*a - d/other.b*other.a;
    return fraction(na, d).simplify();
  }

  fraction operator*(const fraction &other) const {
    return fraction(a*other.a, b*other.b).simplify();
  }

  fraction operator/(const fraction &other) const {
    return fraction(a*other.b, b*other.a).simplify();
  }

  string to_string() const {
    ostringstream s;
    s << a << "/" << b;
    return s.str();
  }
};

struct point {
  fraction x, y;

  point(fraction x, fraction y) : x(x), y(y) {}

  point rotate() const {
    fraction nx = y * fraction(-1, 1);
    fraction ny = x;
    return point(nx, ny);
  }

  point operator+(const point &other) const {
    return point(x + other.x, y + other.y);
  }

  point scale(const ll a, const ll b) const {
    return point(x/fraction(a,1)*fraction(b,1), y/fraction(a,1)*fraction(b,1));
  }

  bool is_integer() const {
    return ((x.a % x.b == 0) && (y.a % y.b == 0));
  }

  string to_string() const {
    ostringstream s;
    s << "(" << x.a << "/" << x.b << ", " << y.a << "/" << y.b << ")";
    return s.str();
  }
};


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll a, b, n; cin >> a >> b >> n;
  ll lo = 0;
  ll hi = 1e8;
  int ans = -1;
  while (lo <= hi) {
    int mid = hi-(hi-lo)/2;
    if (a*mid/2 + b*mid/2 >= n) {
      ans = mid;
      hi = mid-1;
    }
    else lo = mid+1;
  }

  ll right = b*ans/2;
  ll up = a*ans/2;
  
  
  return 0;
}
