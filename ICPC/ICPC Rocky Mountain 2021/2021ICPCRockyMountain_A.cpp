#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

template<typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

ll lcd(ll a, ll b) {
    return a/gcd(a,b)*b;
}

struct frac {
    ll a, b;

    frac() : a(0), b(1) {}
    frac(ll a, ll b) : a(a), b(b) {}

    void reduce() {
        ll g = gcd(abs(a),abs(b));
        int cnt = 0;
        cnt += (a < 0) + (b < 0);
        if (cnt%2 == 0) {
            a = abs(a);
            b = abs(b);
        }
        else {
            a = -abs(a);
            b = abs(b);
        }
        if (g == 0) return;
        a /= g; b /= g;
    }

    double todouble() {
        return (double)a/b;
    }

    frac operator*(const frac &other) const {
        frac res = frac(a*other.a,b*other.b);
        res.reduce();
        return res;
    }
    frac operator/(const frac &other) const {
        frac res = frac(a*other.b,b*other.a);
        res.reduce();
        return res;
    }
    frac operator+(const frac &other) const {
        ll L = lcd(b, other.b);
        frac res = frac(L/b*a+L/other.b*other.a, L);
        res.reduce();
        return res;
    }
    frac operator-(const frac &other) const {
        ll L = lcd(b, other.b);
        frac res = frac(L/b*a-L/other.b*other.a, L);
        res.reduce();
        return res;
    }
    bool operator==(const frac &other) const {
        return a*other.b == b*other.a;
    }
    bool operator<(const frac &other) const {
        return a*other.b < b*other.a;
    }
    bool operator<=(const frac &other) const {
        return a*other.b <= b*other.a;
    }
    bool operator>(const frac &other) const {
        return a*other.b > b*other.a;
    }
    bool operator>=(const frac &other) const {
        return a*other.b >= b*other.a;
    }
};

frac fracmin(const frac &a, const frac &b) {
    if (a <= b) return a;
    return b;
}

frac fracmax(const frac &a, const frac &b) {
    if (a >= b) return a;
    return b;
}

ostream& operator<<(ostream &os, const frac &f) {
    os << f.a << "/" << f.b;
    return os;
}

struct point {
    frac x, y;
    point() : x(frac(0,1)), y(frac(0,1)) {}
    point(frac x, frac y) : x(x), y(y) {}
    bool operator==(const point &other) const {
        return x == other.x && y == other.y;
    }
    bool operator<(const point &other) const {
        if (other.x == x) return y < other.y;
        return x < other.x;
    }
};

const int N = 105;
const point INVALID = point(frac(-1,1), frac(-1,1));
vector<point> polygon;
int n, q; 

vector<frac> get_line(point &a, point &b) {
    frac A = b.y - a.y;
    frac B = a.x - b.x;
    frac C = A*a.x + B*a.y;
    return {A,B,C};
}

point get_intersection(point &a, point &b, point &c, point &d) {
    vector<frac> L1 = get_line(a,b);
    vector<frac> L2 = get_line(c,d);

    frac &A1 = L1[0]; frac &B1 = L1[1]; frac &C1 = L1[2];
    frac &A2 = L2[0]; frac &B2 = L2[1]; frac &C2 = L2[2];

    frac det = A1*B2 - A2*B1;
    if (det.a == 0) return INVALID;
    
    frac x = (B2*C1 - B1*C2)/det;
    frac y = (A1*C2 - A2*C1)/det;

    bool onL1 = (fracmin(a.x,b.x) <= x && fracmax(a.x,b.x) >= x && fracmin(a.y,b.y) <= y && fracmax(a.y,b.y) >= y);
    bool onL2 = (fracmin(c.x,d.x) <= x && fracmax(c.x,d.x) >= x && fracmin(c.y,d.y) <= y && fracmax(c.y,d.y) >= y);
    //cout << L1[0] << endl;
    if (onL1 && onL2) return point(x,y);
    
    return INVALID;
}

frac cross(const point &a, const point &b) {
    return a.x*b.y - a.y*b.x;
}

bool point_in(const point &p, const vector<point> &poly) {
    int n = poly.size();
    int cnt = 0;
    bool valid1 = 0, valid2 = 0;
    for (int i = 0; i < n; i++) {
        point a = poly[i];
        point b = poly[(i+1)%n];
        point c = p;
        point d = point(p.x+frac(2000,1), p.y);
        point e = point(frac(0,1), p.y);

        point intersect1 = get_intersection(a,b,c,d);
        point intersect2 = get_intersection(a,b,c,e);

        if (!(intersect1 == INVALID)) valid1 = 1;
        if (!(intersect2 == INVALID)) valid2 = 1;
    }
    return valid1 && valid2;
}

frac solve(vector<point> &pixel) {
    int n = pixel.size();
    int m = polygon.size();

    vector<point> interpoly;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            point a = pixel[i];
            point b = pixel[(i+1)%n];
            point c = polygon[j];
            point d = polygon[(j+1)%m];

            point intersect = get_intersection(a,b,c,d);
            if (intersect == INVALID) continue;
            interpoly.push_back(intersect);
        }
    }
    for (int i = 0; i < n; i++) {
        if (point_in(pixel[i], polygon)) {
            interpoly.push_back(pixel[i]);
            //cout << pixel[i].x << " " << pixel[i].y << endl;
        }
    }

    for (int j = 0; j < m; j++) {
        if (point_in(polygon[j], pixel)) {
            interpoly.push_back(polygon[j]);
            //cout << polygon[j].x << " " << polygon[j].y << endl;
        }
    }

    // Remove duplicates
    set<point> pset;
    for (point p : interpoly) pset.insert(p);  
    interpoly.clear();
    for (point p : pset) interpoly.push_back(p);

    int k = interpoly.size();
    if (k <= 1) return frac(0,1);
    point center(frac(0,1), frac(0,1));
    for (point p : interpoly) {
        center.x = center.x + p.x;
        center.y = center.y + p.y;
    }
    center.x = center.x / frac(k,1);
    center.y = center.y / frac(k,1);
    //cout << center.x << " " << center.y << endl;
    sort(interpoly.begin(), interpoly.end(), [center](const point &left, const point &right){
        point vec1 = point(left.x-center.x, left.y-center.y);
        point vec2 = point(right.x-center.x, right.y-center.y);
        double angle1 = -atan2(vec1.y.todouble(), -vec1.x.todouble());
        double angle2 = -atan2(vec2.y.todouble(), -vec2.x.todouble());
        return angle1 < angle2;
    });

    frac area = frac(0,1);
    for (int i = 0; i < k; i++) {
        point a = interpoly[i];
        point b = interpoly[(i+1)%k];
        area = area + (a.x*b.y - a.y*b.x);
    }
    area = area / frac(2,1);
    area.reduce();
    return area;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        point p(frac(x,1)+frac(1,2),frac(y,1)+frac(1,2));
        polygon.push_back(p);
    }

    for (int i = 0; i < q; i++) {
        ll a, b; cin >> a >> b;
        vector<point> pixel;
        pixel.push_back(point(frac(a,1), frac(b,1)));
        pixel.push_back(point(frac(a+1,1), frac(b,1)));
        pixel.push_back(point(frac(a+1,1), frac(b+1,1)));
        pixel.push_back(point(frac(a,1), frac(b+1,1)));

        cout << solve(pixel) << endl;
    }

    return 0;
}