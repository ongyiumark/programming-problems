#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6+5;

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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  map<ll,ll> sqrt;
  for (ll i = 0; i < N; i++) sqrt[i*i] = i;

  ll a, b; cin >> a >> b;
  a--; b--;
  // x^2 + y^2 = a^2
  ll cnt = 0;
  for (ll x = -a; x < a; x++) {
    ll tmp = a*a - x*x;
    if (sqrt.find(tmp) == sqrt.end()) continue;
    ll y = sqrt[tmp];

    // (0,0) -> (x,y) is length a
    point p(fraction(x,1), fraction(y,1));
    point vec = p;

    vec = vec.rotate().scale(a, b);
    p = p + vec;
    if (!p.is_integer()) continue;
    
    vec.rotate().scale(b, a);
    p = p + vec;
    if (!p.is_integer()) continue;
    cnt++;
  }
  if (a == b) cnt /= 2;

  cout << cnt << "\n";

  return 0;
}