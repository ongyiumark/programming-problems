#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long double ld;

const int INF = 1e9;
const ll INFLL = 4e18;
const ld EPS = 1e-9;

struct point {
    ld x, y;

    point operator+(const point &other) const {
        point p;
        p.x = x + other.x;
        p.y = y + other.y;
        return p;
    }

    point operator-(const point &other) const {
        point p;
        p.x = x - other.x;
        p.y = y - other.y;
        return p;
    }

    ld dot(const point &other) const {
        return x*other.x + y*other.y;
    }

    ld cross(const point &other) const {
        return x*other.y - y*other.x;
    }
};

struct result {
    point p;
    ld area;
    bool is_rhombus;
    bool is_rect;
};

bool operator<(const result &left, const result &right) {
    if (left.p.x == right.p.x) return left.p.y < right.p.y;
    return left.p.x < right.p.x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    point A, B, C;
    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;

    vector<result> res;
    for (int i = 0; i < 3; i++) {
        point D = B-C+A;
        result tmp;
        tmp.p = D;
        tmp.area = fabs((D.cross(B) + B.cross(C) + C.cross(A) + A.cross(D))/2);
        tmp.is_rhombus = (fabs((A-B).dot(C-D)) < EPS);
        tmp.is_rect = (fabs((A-D).dot(D-B)) < EPS && fabs((B-C).dot(C-A)) < EPS);

        res.push_back(tmp);

        swap(A,B); swap(B,C);
    }

    sort(res.begin(), res.end());

    for (int i = 0; i < 3; i++) {
        printf("point: %.2Lf %.2Lf\n", res[i].p.x, res[i].p.y);
        printf("area: %.2Lf\n", res[i].area);

        string t = (res[i].is_rhombus ? "yes" : "no");
        printf("is rhombus: %s\n", t.c_str());
        t = (res[i].is_rect ? "yes" : "no");
        printf("is rectangle: %s\n", t.c_str());

        printf("-------------------------\n");
    }
    

    return 0;
}